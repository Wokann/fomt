    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 1
    .4byte 4

    .4byte 3
    .2byte 9, 0, 36, 0, 1, 0, 0, 0
    .2byte 9, 9, 42, 36, 1, 0, 0, 0
    .2byte 9, 9, 42, 78, 1, 0, 0, 0

    .4byte 18
    .2byte 252, 33276, 0, 0
    .2byte 33020, 32796, 16, 0
    .2byte 33020, 16428, 0, 0
    .2byte 16412, 33276, 24, 0
    .2byte 28, 16412, 32, 0
    .2byte 32796, 44, 0, 0
    .2byte 16428, 16892, 0, 0
    .2byte 16428, 28, 0, 0
    .2byte 44, 44, 0, 0
    .2byte 252, 33276, 0, 0
    .2byte 33020, 32796, 16, 0
    .2byte 33020, 16428, 0, 0
    .2byte 16412, 33276, 24, 0
    .2byte 28, 16412, 32, 0
    .2byte 32796, 44, 0, 0
    .2byte 16428, 16892, 36, 0
    .2byte 16428, 28, 40, 0
    .2byte 44, 44, 0, 0

    .4byte 120
    .incbin "graphics/shared_resource_087409e4/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_087409e4/full/native.gbapal"

    .4byte 0
    .4byte 4
    .2byte 0, 8
    .2byte 1, 8
    .2byte 2, 8
    .2byte 1, 8
