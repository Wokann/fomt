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
$destinationPath = Join-Path $repositoryRoot 'charmap.txt'
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

Write-Output "Imported charmap.txt with SHA-256 $destinationHash"
