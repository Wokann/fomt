// Print a Ghidra decompilation for the function at, containing, or immediately
// preceding one *physical address in the selected ROM*.  Cross-localization
// assembly labels can deliberately retain a logical address while the JP ROM
// function has shifted; pass the ROM's actual entry, not that logical label.
// The last case is useful for Thumb literal pools: Ghidra normally marks those
// words as data just after their owning function.
//
// Run with:
// analyzeHeadless ... -postScript GhidraDecompileFunction.java 0x080B5004
//
// For a known Thumb function entry which is missing or merged in the imported
// Ghidra database, append --create-thumb.  The script disassembles and creates
// that one function before decompiling it.  This only changes the selected
// analysis project, never the ROM or this repository's build inputs.
// This is an analysis aid only; it is not part of the game build.
// @category FoMT

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.lang.Register;
import ghidra.program.model.lang.RegisterValue;

import java.math.BigInteger;

public class GhidraDecompileFunction extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] arguments = getScriptArgs();
        if (arguments.length != 1 && arguments.length != 2) {
            printerr("usage: GhidraDecompileFunction.java <ROM-address> [--create-thumb]");
            return;
        }
        Address address = toAddr(arguments[0]);
        Function function = getFunctionAt(address);
        if (arguments.length == 2) {
            if (!"--create-thumb".equals(arguments[1])) {
                printerr("unknown option: " + arguments[1]);
                return;
            }
            if (function == null) {
                Register thumbMode = currentProgram.getProgramContext().getRegister("TMode");
                if (thumbMode == null) {
                    printerr("selected program has no ARM Thumb TMode register");
                    return;
                }
                DisassembleCommand command = new DisassembleCommand(address, null, true);
                command.setInitialContext(new RegisterValue(thumbMode, BigInteger.ONE));
                if (!command.applyTo(currentProgram, monitor)) {
                    printerr("could not disassemble Thumb code at " + address);
                    return;
                }
                function = createFunction(address, null);
                if (function == null) {
                    printerr("could not create Thumb function at " + address);
                    return;
                }
                println("created Thumb function " + function.getName() + " @ "
                    + function.getEntryPoint());
            }
        }
        if (function == null) {
            function = getFunctionContaining(address);
        }
        if (function == null) {
            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            while (functions.hasNext()) {
                Function candidate = functions.next();
                if (candidate.getEntryPoint().compareTo(address) > 0) {
                    break;
                }
                function = candidate;
            }
            if (function != null) {
                println("using preceding function " + function.getName()
                    + " for literal/data address " + address);
            }
        }
        if (function == null) {
            printerr("no function at or containing " + address);
            return;
        }
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        DecompileResults result = decompiler.decompileFunction(function, 60, monitor);
        if (!result.decompileCompleted()) {
            printerr("decompilation failed for " + function.getName() + ": " + result.getErrorMessage());
            return;
        }
        println("function: " + function.getName() + " @ " + function.getEntryPoint());
        println(result.getDecompiledFunction().getC());
    }
}
