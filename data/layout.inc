	.ifdef REGION_US
		.include "data/layout/us/rom_layout.inc"
	.elseif REGION_JP
		.include "data/layout/jp/rom_layout.inc"
	.else
		.error "Define exactly one of REGION_US or REGION_JP"
	.endif
