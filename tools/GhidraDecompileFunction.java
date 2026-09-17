// Print a Ghidra decompilation for the function at, containing, or immediately
// preceding one ROM address.  The last case is useful for Thumb literal pools:
// Ghidra normally marks those words as data just after their owning function.
//
// Run with:
// analyzeHeadless ... -postScript GhidraDecompileFunction.java 0x080B5004
// This is an analysis aid only; it is not part of the game build.
// @category FoMT

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class GhidraDecompileFunction extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] arguments = getScriptArgs();
        if (arguments.length != 1) {
            printerr("usage: GhidraDecompileFunction.java <ROM-address>");
            return;
        }
        Address address = toAddr(arguments[0]);
        Function function = getFunctionAt(address);
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
