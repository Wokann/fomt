	.ifdef REGION_US
		.include "data/scripts/us/scripts.inc"
	.else
	.ifdef REGION_JP
		.include "data/scripts/jp/scripts.inc"
	.else
	.ifdef REGION_EU
		.include "data/scripts/eu/scripts.inc"
	.else
	.ifdef REGION_DE
		.include "data/scripts/de/scripts.inc"
	.else
		.error "Define exactly one of REGION_US, REGION_JP, REGION_EU, or REGION_DE"
	.endif
	.endif
	.endif
	.endif
