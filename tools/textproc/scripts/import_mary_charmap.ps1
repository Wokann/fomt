[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [ValidateNotNullOrEmpty()]
    [string]$MaryCharmap
)

$ErrorActionPreference = 'Stop'

$scriptDirectory = Split-Path -Parent $PSCommandPath
$repositoryRoot = (Resolve-Path (Join-Path $scriptDirectory '..\..\..')).Path
$sourcePath = (Resolve-Path -LiteralPath $MaryCharmap).Path
$expectedName = 'charmap_jp.txt'

if ((Split-Path -Leaf $sourcePath) -ne $expectedName) {
    throw "Expected Mary source file '$expectedName', got '$sourcePath'."
}

$destinationPath = Join-Path $repositoryRoot 'charmap_jp.txt'
$legacyPath = Join-Path $repositoryRoot 'data\text\charmap_jp.txt'
$destinationDirectory = Split-Path -Parent $destinationPath
New-Item -ItemType Directory -Force -Path $destinationDirectory | Out-Null

$sourceHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $sourcePath).Hash
if (Test-Path -LiteralPath $destinationPath) {
    $existingHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $destinationPath).Hash
    if ($existingHash -ne $sourceHash) {
        throw "Refusing to overwrite a different project charmap at '$destinationPath'."
    }
} else {
    Copy-Item -LiteralPath $sourcePath -Destination $destinationPath
}
$destinationHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $destinationPath).Hash

if ($sourceHash -ne $destinationHash) {
    throw "Checksum mismatch after importing '$sourcePath'."
}

if (Test-Path -LiteralPath $legacyPath) {
    $legacyHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $legacyPath).Hash
    if ($legacyHash -ne $sourceHash) {
        throw "Refusing to remove a different legacy charmap at '$legacyPath'."
    }
    Remove-Item -LiteralPath $legacyPath -Force
}

Write-Output "Imported $expectedName with SHA-256 $destinationHash"
