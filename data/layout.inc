	.ifdef REGION_US
		.include "data/layout/us/rom_layout.inc"
	.else
	.ifdef REGION_JP
		.include "data/layout/jp/rom_layout.inc"
	.else
	.ifdef REGION_EU
		.include "data/layout/eu/rom_layout.inc"
	.else
	.ifdef REGION_DE
		.include "data/layout/de/rom_layout.inc"
	.else
		.error "Define exactly one of REGION_US, REGION_JP, REGION_EU, or REGION_DE"
	.endif
	.endif
	.endif
	.endif
