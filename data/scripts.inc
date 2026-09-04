	.ifdef REGION_US
		.include "data/scripts/us/scripts.inc"
	.elseif REGION_JP
		.include "data/scripts/jp/scripts.inc"
	.else
		.error "Define exactly one of REGION_US or REGION_JP"
	.endif
