    .include "asm/macro.inc"
    .syntax unified
    .thumb
    .text

    thumb_func_start VarGet__12ScriptEngineUi
VarGet__12ScriptEngineUi:
    push {r4, r5, lr}
    mov r5, r8
    push {r5}
    sub sp, #0xc
    adds r2, r0, #0
    ldr r0, .LvarGet_0020 @ =0x0000024D
    cmp r1, r0
    bls .LvarGet_0014
    bl .LvarGetZero
.LvarGet_0014:
    lsls r0, r1, #2
    ldr r1, .LvarGet_0024 @ =.LvariableReaders
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LvarGet_0020: .word (.LvariableReadersEnd - .LvariableReaders) / 4 - 1
.LvarGet_0024: .word .LvariableReaders
.LvariableReaders: @ jump table
    .word .LvarGet_0960 @ case 0
    .word .LvarGet_098A @ case 1
    .word .LvarGet_0998 @ case 2
    .word .LvarGet_09A4 @ case 3
    .word .LvarGet_09B2 @ case 4
    .word .LvarGet_09C4 @ case 5
    .word .LvarGet_0A06 @ case 6
    .word .LvarGet_0A14 @ case 7
    .word .LvarGet_0A22 @ case 8
    .word .LvarGet_0A3C @ case 9
    .word .LvarGet_0A54 @ case 10
    .word .LvarGet_0A6C @ case 11
    .word .LvarGet_0A84 @ case 12
    .word .LvarGet_0A9C @ case 13
    .word .LvarGet_0B02 @ case 14
    .word .LvarGet_0B18 @ case 15
    .word .LvarGet_0B2E @ case 16
    .word .LvarGet_0B44 @ case 17
    .word .LvarGet_0B52 @ case 18
    .word .LvarGet_0B60 @ case 19
    .word .LvarGet_0B6E @ case 20
    .word .LvarGet_0B82 @ case 21
    .word .LvarGet_0BA2 @ case 22
    .word .LvarGet_0C2E @ case 23
    .word .LvarGet_0BB6 @ case 24
    .word .LvarGet_0BCA @ case 25
    .word .LvarGet_0BDE @ case 26
    .word .LvarGet_0BF2 @ case 27
    .word .LvarGet_0C06 @ case 28
    .word .LvarGet_0C1A @ case 29
    .word .LvarGet_0CE2 @ case 30
    .word .LvarGet_0D58 @ case 31
    .word .LvarGet_0C42 @ case 32
    .word .LvarGet_0C56 @ case 33
    .word .LvarGet_0C6A @ case 34
    .word .LvarGet_0C7E @ case 35
    .word .LvarGet_0C92 @ case 36
    .word .LvarGet_0CA6 @ case 37
    .word .LvarGet_0CBA @ case 38
    .word .LvarGet_0CCE @ case 39
    .word .LvarGet_0AB4 @ case 40
    .word .LvarGet_0AC6 @ case 41
    .word .LvarGet_0ADC @ case 42
    .word .LvarGet_0AF2 @ case 43
    .word .LvarGet_0CF6 @ case 44
    .word .LvarGet_0D40 @ case 45
    .word .LvarGet_0D88 @ case 46
    .word .LvarGet_0DAC @ case 47
    .word .LvarGet_0DD4 @ case 48
    .word .LvarGet_0DF8 @ case 49
    .word .LvarGet_0E6E @ case 50
    .word .LvarGet_0ED8 @ case 51
    .word .LvarGet_0EF4 @ case 52
    .word .LvarGet_0F14 @ case 53
    .word .LvarGet_0E1C @ case 54
    .word .LvarGet_0E22 @ case 55
    .word .LvarGet_0E28 @ case 56
    .word .LvarGet_0E2E @ case 57
    .word .LvarGet_0E34 @ case 58
    .word .LvarGet_0E3A @ case 59
    .word .LvarGet_0E48 @ case 60
    .word .LvarGet_0E4E @ case 61
    .word .LvarGet_0E54 @ case 62
    .word .LvarGet_0E5A @ case 63
    .word .LvarGet_0E60 @ case 64
    .word .LvarGet_0D10 @ case 65
    .word .LvarGet_0D28 @ case 66
    .word .LvarGet_0F2C @ case 67
    .word .LvarGet_0F3C @ case 68
    .word .LvarGet_0F5A @ case 69
    .word .LvarGet_0F8C @ case 70
    .word .LvarGet_0F9A @ case 71
    .word .LvarGet_138C @ case 72
    .word .LvarGet_0FA8 @ case 73
    .word .LvarGet_0FB6 @ case 74
    .word .LvarGet_0FC4 @ case 75
    .word .LvarGet_0FD2 @ case 76
    .word .LvarGet_1328 @ case 77
    .word .LvarGet_0FE0 @ case 78
    .word .LvarGet_0FEE @ case 79
    .word .LvarGet_0FFC @ case 80
    .word .LvarGet_13A0 @ case 81
    .word .LvarGet_100A @ case 82
    .word .LvarGet_13B4 @ case 83
    .word .LvarGet_1018 @ case 84
    .word .LvarGet_1026 @ case 85
    .word .LvarGet_133C @ case 86
    .word .LvarGet_1034 @ case 87
    .word .LvarGet_1042 @ case 88
    .word .LvarGet_13C8 @ case 89
    .word .LvarGet_1050 @ case 90
    .word .LvarGet_13DC @ case 91
    .word .LvarGet_105E @ case 92
    .word .LvarGet_13F0 @ case 93
    .word .LvarGet_106C @ case 94
    .word .LvarGet_107A @ case 95
    .word .LvarGet_1350 @ case 96
    .word .LvarGet_1088 @ case 97
    .word .LvarGet_1096 @ case 98
    .word .LvarGet_1404 @ case 99
    .word .LvarGet_10A4 @ case 100
    .word .LvarGet_10B2 @ case 101
    .word .LvarGet_10C0 @ case 102
    .word .LvarGet_10CE @ case 103
    .word .LvarGet_1364 @ case 104
    .word .LvarGet_10DC @ case 105
    .word .LvarGet_10E8 @ case 106
    .word .LvarGet_10F4 @ case 107
    .word .LvarGet_1418 @ case 108
    .word .LvarGet_1100 @ case 109
    .word .LvarGet_110C @ case 110
    .word .LvarGet_1118 @ case 111
    .word .LvarGet_1378 @ case 112
    .word .LvarGet_1150 @ case 113
    .word .LvarGet_115E @ case 114
    .word .LvarGet_116C @ case 115
    .word .LvarGet_117A @ case 116
    .word .LvarGet_1188 @ case 117
    .word .LvarGet_1196 @ case 118
    .word .LvarGet_11A4 @ case 119
    .word .LvarGet_142C @ case 120
    .word .LvarGet_1490 @ case 121
    .word .LvarGet_11B2 @ case 122
    .word .LvarGet_11C0 @ case 123
    .word .LvarGet_11CE @ case 124
    .word .LvarGet_11DC @ case 125
    .word .LvarGet_11EA @ case 126
    .word .LvarGet_11F8 @ case 127
    .word .LvarGet_1440 @ case 128
    .word .LvarGet_14A4 @ case 129
    .word .LvarGet_1206 @ case 130
    .word .LvarGet_1214 @ case 131
    .word .LvarGet_1222 @ case 132
    .word .LvarGet_1230 @ case 133
    .word .LvarGet_123E @ case 134
    .word .LvarGet_124C @ case 135
    .word .LvarGet_1454 @ case 136
    .word .LvarGet_14B8 @ case 137
    .word .LvarGet_125A @ case 138
    .word .LvarGet_1268 @ case 139
    .word .LvarGet_1276 @ case 140
    .word .LvarGet_1284 @ case 141
    .word .LvarGet_1292 @ case 142
    .word .LvarGet_12A0 @ case 143
    .word .LvarGet_1468 @ case 144
    .word .LvarGet_14CC @ case 145
    .word .LvarGet_12AE @ case 146
    .word .LvarGet_12C4 @ case 147
    .word .LvarGet_12DA @ case 148
    .word .LvarGet_12F0 @ case 149
    .word .LvarGet_1306 @ case 150
    .word .LvarGet_1312 @ case 151
    .word .LvarGet_147C @ case 152
    .word .LvarGet_14E0 @ case 153
    .word .LvarGet_14F4 @ case 154
    .word .LvarGet_1508 @ case 155
    .word .LvarGet_151C @ case 156
    .word .LvarGet_1530 @ case 157
    .word .LvarGet_1544 @ case 158
    .word .LvarGet_1558 @ case 159
    .word .LvarGet_156C @ case 160
    .word .LvarGet_1580 @ case 161
    .word .LvarGet_1594 @ case 162
    .word .LvarGet_15A8 @ case 163
    .word .LvarGet_15CC @ case 164
    .word .LvarGet_15E0 @ case 165
    .word .LvarGet_15F4 @ case 166
    .word .LvarGet_1608 @ case 167
    .word .LvarGet_161C @ case 168
    .word .LvarGet_1630 @ case 169
    .word .LvarGet_1644 @ case 170
    .word .LvarGet_1658 @ case 171
    .word .LvarGet_166C @ case 172
    .word .LvarGet_1680 @ case 173
    .word .LvarGet_1694 @ case 174
    .word .LvarGet_16A8 @ case 175
    .word .LvarGet_16BC @ case 176
    .word .LvarGet_16D0 @ case 177
    .word .LvarGet_16E4 @ case 178
    .word .LvarGet_16F8 @ case 179
    .word .LvarGet_171C @ case 180
    .word .LvarGet_1730 @ case 181
    .word .LvarGet_1744 @ case 182
    .word .LvarGet_1758 @ case 183
    .word .LvarGet_176C @ case 184
    .word .LvarGet_1780 @ case 185
    .word .LvarGet_1794 @ case 186
    .word .LvarGet_17A8 @ case 187
    .word .LvarGet_17BC @ case 188
    .word .LvarGet_17D0 @ case 189
    .word .LvarGet_17E4 @ case 190
    .word .LvarGet_17F8 @ case 191
    .word .LvarGet_180C @ case 192
    .word .LvarGet_1820 @ case 193
    .word .LvarGet_1834 @ case 194
    .word .LvarGet_1848 @ case 195
    .word .LvarGet_186C @ case 196
    .word .LvarGet_1880 @ case 197
    .word .LvarGet_1894 @ case 198
    .word .LvarGet_18A8 @ case 199
    .word .LvarGet_18BC @ case 200
    .word .LvarGet_18D0 @ case 201
    .word .LvarGet_18E4 @ case 202
    .word .LvarGet_18F8 @ case 203
    .word .LvarGet_190C @ case 204
    .word .LvarGet_1920 @ case 205
    .word .LvarGet_1934 @ case 206
    .word .LvarGet_1948 @ case 207
    .word .LvarGet_195C @ case 208
    .word .LvarGet_1970 @ case 209
    .word .LvarGet_1984 @ case 210
    .word .LvarGet_1998 @ case 211
    .word .LvarGet_19BC @ case 212
    .word .LvarGet_19D0 @ case 213
    .word .LvarGet_19E4 @ case 214
    .word .LvarGet_19F8 @ case 215
    .word .LvarGet_1A0C @ case 216
    .word .LvarGet_1A20 @ case 217
    .word .LvarGet_1A34 @ case 218
    .word .LvarGet_1A48 @ case 219
    .word .LvarGet_1A5C @ case 220
    .word .LvarGet_1A70 @ case 221
    .word .LvarGet_1A84 @ case 222
    .word .LvarGet_1AB0 @ case 223
    .word .LvarGet_1AC4 @ case 224
    .word .LvarGet_1AD8 @ case 225
    .word .LvarGet_1AEC @ case 226
    .word .LvarGet_1B00 @ case 227
    .word .LvarGet_1B14 @ case 228
    .word .LvarGet_1B28 @ case 229
    .word .LvarGet_1B3C @ case 230
    .word .LvarGet_1B50 @ case 231
    .word .LvarGet_1B64 @ case 232
    .word .LvarGet_1B78 @ case 233
    .word .LvarGet_1B8C @ case 234
    .word .LvarGet_1BA0 @ case 235
    .word .LvarGet_1BB4 @ case 236
    .word .LvarGet_1BC8 @ case 237
    .word .LvarGet_1BDC @ case 238
    .word .LvarGet_1BF0 @ case 239
    .word .LvarGet_1C04 @ case 240
    .word .LvarGet_1C18 @ case 241
    .word .LvarGet_1C2C @ case 242
    .word .LvarGet_1C40 @ case 243
    .word .LvarGet_1C54 @ case 244
    .word .LvarGet_1C68 @ case 245
    .word .LvarGet_1C7C @ case 246
    .word .LvarGet_1C90 @ case 247
    .word .LvarGet_1CA4 @ case 248
    .word .LvarGet_1CB8 @ case 249
    .word .LvarGet_1CCC @ case 250
    .word .LvarGet_1CE0 @ case 251
    .word .LvarGet_1CF4 @ case 252
    .word .LvarGet_1D08 @ case 253
    .word .LvarGet_1D1C @ case 254
    .word .LvarGet_1D30 @ case 255
    .word .LvarGet_1D44 @ case 256
    .word .LvarGet_1D58 @ case 257
    .word .LvarGet_1D6C @ case 258
    .word .LvarGet_1D80 @ case 259
    .word .LvarGet_1D9C @ case 260
    .word .LvarGet_1DB0 @ case 261
    .word .LvarGet_1DC4 @ case 262
    .word .LvarGet_1DD8 @ case 263
    .word .LvarGet_1DEC @ case 264
    .word .LvarGet_1DFC @ case 265
    .word .LvarGet_1E10 @ case 266
    .word .LvarGet_1E24 @ case 267
    .word .LvarGet_1E38 @ case 268
    .word .LvarGet_1E4C @ case 269
    .word .LvarGet_1E68 @ case 270
    .word .LvarGet_1E7C @ case 271
    .word .LvarGet_1EA0 @ case 272
    .word .LvarGet_1EB4 @ case 273
    .word .LvarGet_1EC8 @ case 274
    .word .LvarGet_1EDC @ case 275: unknown boolean prerequisite
    .word .LvarGet_1EF0 @ case 276
    .word .LvarGet_1F04 @ case 277
    .word .LvarGet_1F18 @ case 278
    .word .LvarGet_1F2C @ case 279
    .word .LvarGet_1F40 @ case 280
    .word .LvarGet_1F54 @ case 281
    .word .LvarGet_1F68 @ case 282
    .word .LvarGet_1F7C @ case 283
    .word .LvarGet_1F90 @ case 284
    .word .LvarGet_1FA4 @ case 285
    .word .LvarGet_1FB8 @ case 286
    .word .LvarGet_1FCC @ case 287
    .word .LvarGet_1FE0 @ case 288
    .word .LvarGet_1FF0 @ case 289
    .word .LvarGet_2000 @ case 290
    .word .LvarGet_2010 @ case 291
    .word .LvarGet_2020 @ case 292
    .word .LvarGet_2034 @ case 293
    .word .LvarGet_2048 @ case 294
    .word .LvarGet_205C @ case 295
    .word .LvarGet_2070 @ case 296
    .word .LvarGet_2084 @ case 297
    .word .LvarGet_2098 @ case 298
    .word .LvarGet_20AC @ case 299
    .word .LvarGet_20C0 @ case 300
    .word .LvarGet_20D4 @ case 301
    .word .LvarGet_20E8 @ case 302
    .word .LvarGet_20FC @ case 303
    .word .LvarGet_2110 @ case 304
    .word .LvarGet_2134 @ case 305
    .word .LvarGet_2148 @ case 306
    .word .LvarGet_215C @ case 307
    .word .LvarGet_2170 @ case 308
    .word .LvarGet_2184 @ case 309
    .word .LvarGet_2198 @ case 310
    .word .LvarGet_21AC @ case 311
    .word .LvarGet_21C0 @ case 312
    .word .LvarGet_21D4 @ case 313
    .word .LvarGet_21E8 @ case 314
    .word .LvarGet_2204 @ case 315
    .word .LvarGet_2218 @ case 316
    .word .LvarGet_222C @ case 317
    .word .LvarGet_2240 @ case 318
    .word .LvarGet_2254 @ case 319
    .word .LvarGet_2268 @ case 320
    .word .LvarGet_228C @ case 321
    .word .LvarGet_22A0 @ case 322
    .word .LvarGet_22B4 @ case 323
    .word .LvarGet_22C8 @ case 324
    .word .LvarGet_22DC @ case 325
    .word .LvarGet_22F0 @ case 326
    .word .LvarGet_2304 @ case 327
    .word .LvarGet_2320 @ case 328
    .word .LvarGet_2334 @ case 329
    .word .LvarGet_2348 @ case 330
    .word .LvarGet_235C @ case 331
    .word .LvarGet_2370 @ case 332
    .word .LvarGet_2384 @ case 333
    .word .LvarGet_23B0 @ case 334
    .word .LvarGet_23C4 @ case 335
    .word .LvarGet_23D8 @ case 336
    .word .LvarGet_23EC @ case 337
    .word .LvarGet_2400 @ case 338
    .word .LvarGet_2414 @ case 339
    .word .LvarGet_2428 @ case 340
    .word .LvarGet_2444 @ case 341
    .word .LvarGet_2458 @ case 342
    .word .LvarGet_246C @ case 343
    .word .LvarGet_2480 @ case 344
    .word .LvarGet_2494 @ case 345
    .word .LvarGet_24A8 @ case 346
    .word .LvarGet_24BC @ case 347
    .word .LvarGet_24D0 @ case 348
    .word .LvarGet_24E4 @ case 349
    .word .LvarGet_24F8 @ case 350
    .word .LvarGet_250C @ case 351
    .word .LvarGet_2520 @ case 352
    .word .LvarGet_2534 @ case 353
    .word .LvarGet_2548 @ case 354
    .word .LvarGet_255C @ case 355
    .word .LvarGet_2570 @ case 356
    .word .LvarGet_2584 @ case 357
    .word .LvarGet_2598 @ case 358
    .word .LvarGet_25AC @ case 359
    .word .LvarGet_25C0 @ case 360
    .word .LvarGet_25D4 @ case 361
    .word .LvarGet_25E8 @ case 362
    .word .LvarGet_25FC @ case 363
    .word .LvarGet_2610 @ case 364
    .word .LvarGet_2624 @ case 365
    .word .LvarGet_2638 @ case 366
    .word .LvarGet_264C @ case 367
    .word .LvarGet_2660 @ case 368
    .word .LvarGet_2674 @ case 369
    .word .LvarGet_1126 @ case 370
    .word .LvarGet_1136 @ case 371
    .word .LvarGet_2688 @ case 372
    .word .LvarGet_269C @ case 373
    .word .LvarGet_26B0 @ case 374
    .word .LvarGet_26C4 @ case 375
    .word .LvarGet_26D8 @ case 376
    .word .LvarGet_26EC @ case 377
    .word .LvarGet_2700 @ case 378
    .word .LvarGet_2714 @ case 379
    .word .LvarGet_2728 @ case 380
    .word .LvarGet_273C @ case 381
    .word .LvarGet_2750 @ case 382
    .word .LvarGet_2764 @ case 383
    .word .LvarGet_2778 @ case 384
    .word .LvarGet_278C @ case 385
    .word .LvarGet_27A0 @ case 386
    .word .LvarGet_27B4 @ case 387
    .word .LvarGet_27C8 @ case 388
    .word .LvarGet_27DC @ case 389
    .word .LvarGet_27F0 @ case 390
    .word .LvarGet_2804 @ case 391
    .word .LvarGet_2820 @ case 392
    .word .LvarGet_2834 @ case 393
    .word .LvarGet_2848 @ case 394
    .word .LvarGet_285C @ case 395
    .word .LvarGet_286C @ case 396
    .word .LvarGet_287C @ case 397
    .word .LvarGet_2898 @ case 398
    .word .LvarGet_28AC @ case 399
    .word .LvarGet_28C0 @ case 400
    .word .LvarGet_0F78 @ case 401
    .word .LvarGet_28E4 @ case 402
    .word .LvarGet_28F8 @ case 403
    .word .LvarGet_290C @ case 404
    .word .LvarGet_291C @ case 405
    .word .LvarGet_2930 @ case 406
    .word .LvarGet_2944 @ case 407
    .word .LvarGet_2958 @ case 408
    .word .LvarGet_2968 @ case 409
    .word .LvarGet_297C @ case 410
    .word .LvarGet_2990 @ case 411
    .word .LvarGet_29A4 @ case 412
    .word .LvarGet_29B4 @ case 413
    .word .LvarGet_29C8 @ case 414
    .word .LvarGet_29DC @ case 415
    .word .LvarGet_29EC @ case 416
    .word .LvarGet_29FC @ case 417
    .word .LvarGet_2A10 @ case 418
    .word .LvarGet_2A24 @ case 419
    .word .LvarGet_2A38 @ case 420
    .word .LvarGet_2A4C @ case 421
    .word .LvarGet_2A60 @ case 422
    .word .LvarGet_2A74 @ case 423: unknown daily-reset boolean
    .word .LvarGet_2A88 @ case 424
    .word .LvarGet_2A98 @ case 425
    .word .LvarGet_2AB4 @ case 426
    .word .LvarGet_2AC8 @ case 427
    .word .LvarGet_2ADC @ case 428
    .word .LvarGet_2AEC @ case 429
    .word .LvarGet_2B00 @ case 430
    .word .LvarGet_2B14 @ case 431
    .word .LvarGet_2B28 @ case 432
    .word .LvarGet_2B38 @ case 433
    .word .LvarGet_2B4C @ case 434
    .word .LvarGet_2B60 @ case 435
    .word .LvarGet_2B74 @ case 436
    .word .LvarGet_2B88 @ case 437
    .word .LvarGet_2B9C @ case 438
    .word .LvarGet_2BB0 @ case 439
    .word .LvarGet_2BC4 @ case 440
    .word .LvarGet_2BE8 @ case 441
    .word .LvarGet_2BFC @ case 442
    .word .LvarGet_2C10 @ case 443
    .word .LvarGet_2C24 @ case 444
    .word .LvarGet_2C34 @ case 445
    .word .LvarGet_2C48 @ case 446
    .word .LvarGet_2C5C @ case 447
    .word .LvarGet_2C70 @ case 448
    .word .LvarGet_2C80 @ case 449
    .word .LvarGet_2C90 @ case 450
    .word .LvarGet_2CAC @ case 451
    .word .LvarGet_2CC0 @ case 452
    .word .LvarGet_2CD4 @ case 453
    .word .LvarGet_2CE8 @ case 454
    .word .LvarGet_2CFC @ case 455
    .word .LvarGet_2D10 @ case 456
    .word .LvarGet_2D2C @ case 457
    .word .LvarGet_2D3C @ case 458
    .word .LvarGet_2D4C @ case 459
    .word .LvarGet_2D68 @ case 460
    .word .LvarGet_2D8C @ case 461
    .word .LvarGet_2D9C @ case 462
    .word .LvarGet_2DB8 @ case 463
    .word .LvarGet_2DD0 @ case 464
    .word .LvarGet_2DE4 @ case 465
    .word .LvarGet_2DF8 @ case 466
    .word .LvarGet_2E0C @ case 467
    .word .LvarGet_2E20 @ case 468
    .word .LvarGet_2E34 @ case 469
    .word .LvarGet_2E48 @ case 470
    .word .LvarGet_2E5C @ case 471
    .word .LvarGet_2E6C @ case 472
    .word .LvarGet_2E80 @ case 473
    .word .LvarGet_2E94 @ case 474
    .word .LvarGet_2EA8 @ case 475
    .word .LvarGet_2EBC @ case 476
    .word .LvarGet_2ED0 @ case 477
    .word .LvarGet_2EE4 @ case 478
    .word .LvarGet_2EF8 @ case 479
    .word .LvarGet_2F08 @ case 480
    .word .LvarGet_2F1C @ case 481
    .word .LvarGet_2F30 @ case 482
    .word .LvarGet_2F40 @ case 483
    .word .LvarGet_2F50 @ case 484
    .word .LvarGet_2F60 @ case 485
    .word .LvarGet_2F7C @ case 486
    .word .LvarGet_2F8C @ case 487
    .word .LvarGet_2F9C @ case 488
    .word .LvarGet_2FAC @ case 489
    .word .LvarGet_2FC8 @ case 490
    .word .LvarGet_2FD8 @ case 491
    .word .LvarGet_2FF4 @ case 492
    .word .LvarGet_3010 @ case 493
    .word .LvarGet_3038 @ case 494
    .word .LvarGet_3050 @ case 495
    .word .LvarGet_3068 @ case 496
    .word .LvarGet_3078 @ case 497
    .word .LvarGet_3088 @ case 498
    .word .LvarGet_3098 @ case 499
    .word .LvarGet_30A8 @ case 500
    .word .LvarGet_30B8 @ case 501
    .word .LvarGet_30C8 @ case 502
    .word .LvarGet_30D8 @ case 503
    .word .LvarGet_30E8 @ case 504
    .word .LvarGet_30F8 @ case 505
    .word .LvarGet_3108 @ case 506
    .word .LvarGet_3118 @ case 507
    .word .LvarGet_3128 @ case 508
    .word .LvarGet_3140 @ case 509
    .word .LvarGet_3158 @ case 510
    .word .LvarGet_3180 @ case 511
    .word .LvarGet_3190 @ case 512
    .word .LvarGet_31A0 @ case 513
    .word .LvarGet_31B0 @ case 514
    .word .LvarGet_31C0 @ case 515
    .word .LvarGet_31D0 @ case 516
    .word .LvarGet_31E0 @ case 517
    .word .LvarGet_31F0 @ case 518
    .word .LvarGet_3200 @ case 519
    .word .LvarGet_3210 @ case 520
    .word .LvarGet_3220 @ case 521
    .word .LvarGet_3230 @ case 522
    .word .LvarGet_3240 @ case 523
    .word .LvarGet_3250 @ case 524
    .word .LvarGet_3260 @ case 525
    .word .LvarGet_3278 @ case 526
    .word .LvarGet_3288 @ case 527
    .word .LvarGet_3298 @ case 528
    .word .LvarGet_32A8 @ case 529
    .word .LvarGet_32B8 @ case 530
    .word .LvarGet_32C8 @ case 531
    .word .LvarGet_32D8 @ case 532
    .word .LvarGet_32E8 @ case 533
    .word .LvarGet_32F8 @ case 534
    .word .LvarGet_3310 @ case 535
    .word .LvarGet_3320 @ case 536
    .word .LvarGet_3330 @ case 537
    .word .LvarGet_3340 @ case 538
    .word .LvarGet_3350 @ case 539
    .word .LvarGet_3360 @ case 540
    .word .LvarGet_3370 @ case 541
    .word .LvarGet_3380 @ case 542
    .word .LvarGet_3390 @ case 543
    .word .LvarGet_33A0 @ case 544
    .word .LvarGet_33B0 @ case 545
    .word .LvarGet_33C0 @ case 546
    .word .LvarGet_33D0 @ case 547
    .word .LvarGet_33E0 @ case 548
    .word .LvarGet_33F0 @ case 549
    .word .LvarGet_3400 @ case 550
    .word .LvarGet_3410 @ case 551
    .word .LvarGet_3420 @ case 552
    .word .LvarGet_3430 @ case 553
    .word .LvarGet_3440 @ case 554
    .word .LvarGet_3450 @ case 555
    .word .LvarGet_3460 @ case 556
    .word .LvarGet_3470 @ case 557
    .word .LvarGet_3480 @ case 558
    .word .LvarGet_3490 @ case 559
    .word .LvarGet_34A0 @ case 560
    .word .LvarGet_34B0 @ case 561
    .word .LvarGet_34C0 @ case 562
    .word .LvarGet_34D0 @ case 563
    .word .LvarGet_34E0 @ case 564
    .word .LvarGet_34F0 @ case 565
    .word .LvarGet_3500 @ case 566
    .word .LvarGet_3510 @ case 567
    .word .LvarGet_3520 @ case 568
    .word .LvarGet_3538 @ case 569
    .word .LvarGet_3548 @ case 570
    .word .LvarGet_3560 @ case 571
    .word .LvarGet_3578 @ case 572
    .word .LvarGet_3588 @ case 573
    .word .LvarGet_3598 @ case 574
    .word .LvarGet_35B0 @ case 575
    .word .LvarGet_35C8 @ case 576
    .word .LvarGet_35E0 @ case 577
    .word .LvarGet_35F0 @ case 578
    .word .LvarGet_3600 @ case 579
    .word .LvarGet_3618 @ case 580
    .word .LvarGet_3630 @ case 581
    .word .LvarGet_3648 @ case 582
    .word .LvarGet_3660 @ case 583
    .word .LvarGet_3678 @ case 584
    .word .LvarGet_3688 @ case 585
    .word .LvarGet_3698 @ case 586
    .word .LvarGet_36B0 @ case 587
    .word .LvarGet_36C8 @ case 588
    .word .LvarGet_0D6E @ case 589
.LvariableReadersEnd:
.LvarGet_0960:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r3, #0xc8
    str r3, [sp, #4]
    ldrb r0, [r0, #0x10]
    lsrs r2, r0, #3
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r0, r0, #0x1d
    lsrs r0, r0, #0x1d
    adds r1, r1, r0
    str r1, [sp, #8]
    add r2, sp, #8
    add r0, sp, #4
    cmp r3, r1
    bhi .LvarGet_0986
    b .LvarGet_0F82
.LvarGet_0986:
    adds r0, r2, #0
    b .LvarGet_0F82
.LvarGet_098A:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldrb r0, [r0, #0x11]
    bl .LvarGet_3626
.LvarGet_0998:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldrb r0, [r0, #0x11]
    b .LvarGet_0F06
.LvarGet_09A4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldrb r0, [r0, #0x12]
    bl .LvarGetMaskFiveBits
.LvarGet_09B2:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldrh r0, [r0, #0x12]
    lsls r0, r0, #0x15
    lsrs r0, r0, #0x1a
    bl .LvarGetReturn
.LvarGet_09C4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldrb r2, [r0, #0x10]
    lsls r2, r2, #0x1d
    lsrs r2, r2, #0x1d
    ldrb r3, [r0, #0x11]
    lsls r0, r3, #0x1e
    lsrs r0, r0, #0x1e
    lsls r3, r3, #0x19
    lsrs r3, r3, #0x1b
    adds r2, #6
    lsls r1, r0, #4
    subs r1, r1, r0
    lsls r1, r1, #1
    lsls r0, r2, #4
    subs r0, r0, r2
    lsls r0, r0, #3
    adds r1, r1, r0
    adds r3, r3, r1
    cmp r3, #6
    bls .LvarGet_09FC
    adds r0, r3, #0
    movs r1, #7
    bl __umodsi3
    adds r3, r0, #0
.LvarGet_09FC:
    movs r0, #7
    ands r3, r0
    adds r0, r3, #0
    bl .LvarGetReturn
.LvarGet_0A06:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r0, [r0, #8]
    bl .LvarGetReturn
.LvarGet_0A14:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r0, [r0, #0xc]
    bl .LvarGetReturn
.LvarGet_0A22:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0A38 @ =0x00001BD8
    adds r0, r0, r2
    bl GetBirthday__C6Farmer
    bl .LvarGet_3626
    .align 2, 0
.LvarGet_0A38: .word 0x00001BD8
.LvarGet_0A3C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0A50 @ =0x00001BD8
    adds r0, r0, r2
    bl GetBirthday__C6Farmer
    b .LvarGet_0F06
    .align 2, 0
.LvarGet_0A50: .word 0x00001BD8
.LvarGet_0A54:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0A68 @ =0x00001BD8
    adds r0, r0, r2
    bl func_0800E4F0
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0A68: .word 0x00001BD8
.LvarGet_0A6C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0A80 @ =0x00001BD8
    adds r0, r0, r2
    bl func_0800E51C
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0A80: .word 0x00001BD8
.LvarGet_0A84:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0A98 @ =0x00001BD8
    adds r0, r0, r2
    bl func_0800E4FC
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0A98: .word 0x00001BD8
.LvarGet_0A9C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0AB0 @ =0x00001BD8
    adds r0, r0, r2
    bl func_0800E53C
    b .LvarGet_0DC8
    .align 2, 0
.LvarGet_0AB0: .word 0x00001BD8
.LvarGet_0AB4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    adds r0, #0x14
    bl GetUnk10__C4Farm
    bl .LvarGetReturn
.LvarGet_0AC6:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r0, r0, r2
    bl GetStoredBushelCount__C4Barn
    bl .LvarGetReturn
.LvarGet_0ADC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0x82
    lsls r2, r2, #3
    adds r0, r0, r2
    bl GetStoredBushelCount__C4Coop
    bl .LvarGetReturn
.LvarGet_0AF2:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    adds r0, #0x14
    bl GetUnkFlag11__C4Farm
    b .LvarGet_0DC8
.LvarGet_0B02:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl GetUpgradeLevel__C9FarmHouse
    bl .LvarGetReturn
.LvarGet_0B18:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0x82
    lsls r2, r2, #3
    adds r0, r0, r2
    bl GetUpgradeLevel__C4Coop
    bl .LvarGetReturn
.LvarGet_0B2E:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r0, r0, r2
    bl GetUpgradeLevel__C4Barn
    bl .LvarGetReturn
.LvarGet_0B44:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    bl GetFlag0__C18GameStateSaveImage
    b .LvarGet_0DC8
.LvarGet_0B52:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    bl GetFlag1__C18GameStateSaveImage
    b .LvarGet_0DC8
.LvarGet_0B60:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    bl GetFlag2__C18GameStateSaveImage
    b .LvarGet_0DC8
.LvarGet_0B6E:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasBathroom__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0B82:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl GetFridge__9FarmHouse
.LvarGet_0B94:
    cmp r0, #0
    bne .LvarGet_0B9C
    bl .LvarGetReturn
.LvarGet_0B9C:
    movs r0, #1
    bl .LvarGetReturn
.LvarGet_0BA2:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl GetShelf__9FarmHouse
    b .LvarGet_0B94
.LvarGet_0BB6:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasCarpet__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0BCA:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasLargeBed__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0BDE:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasMirror__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0BF2:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasClock__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0C06:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasVase__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0C1A:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl GetRecordPlayer__9FarmHouse
    b .LvarGet_0B94
.LvarGet_0C2E:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasKitchen__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0C42:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasKitchenKnife__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0C56:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasKitchenFryingPan__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0C6A:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasKitchenPot__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0C7E:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasKitchenMixer__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0C92:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasKitchenWhisk__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0CA6:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasKitchenRollingPin__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0CBA:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasKitchenOven__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0CCE:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasKitchenSeasoningSet__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0CE2:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl HasStocking__C9FarmHouse
    b .LvarGet_0DC8
.LvarGet_0CF6:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0D0C @ =0x00001C38
    adds r0, r0, r2
    bl GetUpgradeLevel__C8Rucksack
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0D0C: .word 0x00001C38
.LvarGet_0D10:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0D24 @ =0x00001C70
    adds r0, r0, r2
    bl GetGrowthStage__C3Dog
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0D24: .word 0x00001C70
.LvarGet_0D28:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0D3C @ =0x00001C70
    adds r0, r0, r2
    bl GetAffection__C6Animal
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0D3C: .word 0x00001C70
.LvarGet_0D40:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0D54 @ =0x00001BD8
    adds r0, r0, r2
    bl GetStepCount__C6Farmer
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0D54: .word 0x00001BD8
.LvarGet_0D58:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl GetStockingArticleId__C9FarmHouse
    bl .LvarGetReturn
.LvarGet_0D6E:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0D84 @ =0x00001CD4
    adds r0, r0, r2
    bl func_080A039C
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0D84: .word 0x00001CD4
.LvarGet_0D88:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0DA8 @ =0x00001CD4
    adds r0, r0, r2
    bl GetChild__13NpcCollection
    cmp r0, #0
    bne .LvarGet_0DA0
    bl .LvarGetZero
.LvarGet_0DA0:
    bl GetAgeDays__C5Child
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0DA8: .word 0x00001CD4
.LvarGet_0DAC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0DD0 @ =0x00001CD4
    adds r0, r0, r2
    bl GetChild__13NpcCollection
    cmp r0, #0
    bne .LvarGet_0DC4
    bl .LvarGetZero
.LvarGet_0DC4:
    bl CanWalk__C5Child
.LvarGet_0DC8:
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0DD0: .word 0x00001CD4
.LvarGet_0DD4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0DF4 @ =0x00001CD4
    adds r0, r0, r2
    bl GetChild__13NpcCollection
    cmp r0, #0
    bne .LvarGet_0DEC
    bl .LvarGetZero
.LvarGet_0DEC:
    bl GetBirthdayCode__C5Child
    bl .LvarGet_3626
    .align 2, 0
.LvarGet_0DF4: .word 0x00001CD4
.LvarGet_0DF8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0E18 @ =0x00001CD4
    adds r0, r0, r2
    bl GetChild__13NpcCollection
    cmp r0, #0
    bne .LvarGet_0E10
    bl .LvarGetZero
.LvarGet_0E10:
    bl GetBirthdayCode__C5Child
    b .LvarGet_0F06
    .align 2, 0
.LvarGet_0E18: .word 0x00001CD4
.LvarGet_0E1C:
    adds r0, r2, #0
    movs r1, #0x13
    b .LvarGet_0E3E
.LvarGet_0E22:
    adds r0, r2, #0
    movs r1, #3
    b .LvarGet_0E3E
.LvarGet_0E28:
    adds r0, r2, #0
    movs r1, #0xc
    b .LvarGet_0E3E
.LvarGet_0E2E:
    adds r0, r2, #0
    movs r1, #0x15
    b .LvarGet_0E3E
.LvarGet_0E34:
    adds r0, r2, #0
    movs r1, #0x19
    b .LvarGet_0E3E
.LvarGet_0E3A:
    adds r0, r2, #0
    movs r1, #0x1f
.LvarGet_0E3E:
    movs r2, #0
    bl func_08045584
    bl .LvarGetReturn
.LvarGet_0E48:
    adds r0, r2, #0
    movs r1, #0x13
    b .LvarGet_0E64
.LvarGet_0E4E:
    adds r0, r2, #0
    movs r1, #3
    b .LvarGet_0E64
.LvarGet_0E54:
    adds r0, r2, #0
    movs r1, #0xc
    b .LvarGet_0E64
.LvarGet_0E5A:
    adds r0, r2, #0
    movs r1, #0x15
    b .LvarGet_0E64
.LvarGet_0E60:
    adds r0, r2, #0
    movs r1, #0x19
.LvarGet_0E64:
    movs r2, #1
    bl func_08045584
    bl .LvarGetReturn
.LvarGet_0E6E:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r5, [r0]
    ldr r0, .LvarGet_0ECC @ =0x0000214C
    adds r4, r5, r0
    ldrb r1, [r4, #0x1b]
    lsrs r1, r1, #7
    ldrb r3, [r4, #0x1c]
    movs r0, #1
    ands r0, r3
    lsls r0, r0, #1
    orrs r0, r1
    cmp r0, #2
    beq .LvarGet_0EC0
    lsls r0, r3, #0x1d
    lsrs r0, r0, #0x1e
    cmp r0, #2
    beq .LvarGet_0EC0
    lsls r0, r3, #0x1b
    lsrs r0, r0, #0x1e
    cmp r0, #2
    beq .LvarGet_0EC0
    lsls r0, r3, #0x19
    lsrs r0, r0, #0x1e
    cmp r0, #2
    beq .LvarGet_0EC0
    ldrh r0, [r4, #0x1c]
    lsls r0, r0, #0x17
    lsrs r0, r0, #0x1e
    cmp r0, #2
    beq .LvarGet_0EC0
    ldr r1, .LvarGet_0ED0 @ =0x00002197
    adds r0, r5, r1
    ldrb r0, [r0]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #2
    beq .LvarGet_0EC0
    bl .LvarGetZero
.LvarGet_0EC0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0ED4 @ =0x00002144
    b .LvarGet_0F80
    .align 2, 0
.LvarGet_0ECC: .word 0x0000214C
.LvarGet_0ED0: .word 0x00002197
.LvarGet_0ED4: .word 0x00002144
.LvarGet_0ED8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0EF0 @ =0x00001CD4
    adds r0, r0, r2
    bl GetWeddingDate__C13NpcCollection
    ldrb r0, [r0, #1]
    bl .LvarGet_3626
    .align 2, 0
.LvarGet_0EF0: .word 0x00001CD4
.LvarGet_0EF4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0F10 @ =0x00001CD4
    adds r0, r0, r2
    bl GetWeddingDate__C13NpcCollection
    ldrb r0, [r0, #1]
.LvarGet_0F06:
    lsls r0, r0, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0F10: .word 0x00001CD4
.LvarGet_0F14:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_0F28 @ =0x00002148
    adds r0, r0, r2
    ldrb r0, [r0]
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0F28: .word 0x00002148
.LvarGet_0F2C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    adds r0, #0x14
    bl GetHorse__4Farm
    b .LvarGet_0B94
.LvarGet_0F3C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    adds r0, #0x14
    bl GetHorse__4Farm
    cmp r0, #0
    bne .LvarGet_0F52
    bl .LvarGetZero
.LvarGet_0F52:
    bl GetGrowthStage__C5Horse
    bl .LvarGetReturn
.LvarGet_0F5A:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    adds r0, #0x14
    bl GetHorse__4Farm
    cmp r0, #0
    bne .LvarGet_0F70
    bl .LvarGetZero
.LvarGet_0F70:
    bl GetAffection__C6Animal
    bl .LvarGetReturn
.LvarGet_0F78:
    ldr r0, .LvarGet_0F88 @ =gUnk_0300040C
    ldr r0, [r0]
    movs r2, #0xda
    lsls r2, r2, #2
.LvarGet_0F80:
    adds r0, r0, r2
.LvarGet_0F82:
    ldr r0, [r0]
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_0F88: .word gUnk_0300040C
.LvarGet_0F8C:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x46
    movs r2, #0x13
    b .LvarGet_12BA
.LvarGet_0F9A:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x47
    movs r2, #0x13
    b .LvarGet_12D0
.LvarGet_0FA8:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x49
    movs r2, #0x13
    b .LvarGet_12E6
.LvarGet_0FB6:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x4a
    movs r2, #0x13
    b .LvarGet_12FC
.LvarGet_0FC4:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x4b
    movs r2, #0x13
    b .LvarGet_131E
.LvarGet_0FD2:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x4c
    movs r2, #0x13
    b .LvarGet_1142
.LvarGet_0FE0:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x4e
    movs r2, #3
    b .LvarGet_12BA
.LvarGet_0FEE:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x4f
    movs r2, #3
    b .LvarGet_12D0
.LvarGet_0FFC:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x50
    movs r2, #3
    b .LvarGet_12E6
.LvarGet_100A:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x52
    movs r2, #3
    b .LvarGet_12FC
.LvarGet_1018:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x54
    movs r2, #3
    b .LvarGet_131E
.LvarGet_1026:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x55
    movs r2, #3
    b .LvarGet_1142
.LvarGet_1034:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x57
    movs r2, #0x19
    b .LvarGet_12BA
.LvarGet_1042:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x58
    movs r2, #0x19
    b .LvarGet_12D0
.LvarGet_1050:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x5a
    movs r2, #0x19
    b .LvarGet_12E6
.LvarGet_105E:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x5c
    movs r2, #0x19
    b .LvarGet_12FC
.LvarGet_106C:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x5e
    movs r2, #0x19
    b .LvarGet_131E
.LvarGet_107A:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x5f
    movs r2, #0x19
    b .LvarGet_1142
.LvarGet_1088:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x61
    movs r2, #0xc
    b .LvarGet_12BA
.LvarGet_1096:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x62
    movs r2, #0xc
    b .LvarGet_12D0
.LvarGet_10A4:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x64
    movs r2, #0xc
    b .LvarGet_12E6
.LvarGet_10B2:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x65
    movs r2, #0xc
    b .LvarGet_12FC
.LvarGet_10C0:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x66
    movs r2, #0xc
    b .LvarGet_131E
.LvarGet_10CE:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x67
    movs r2, #0xc
    b .LvarGet_1142
.LvarGet_10DC:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x69
    b .LvarGet_12B8
.LvarGet_10E8:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x6a
    b .LvarGet_12CE
.LvarGet_10F4:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x6b
    b .LvarGet_12E4
.LvarGet_1100:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x6d
    b .LvarGet_12FA
.LvarGet_110C:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x6e
    b .LvarGet_131C
.LvarGet_1118:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x6f
    movs r2, #0x15
    b .LvarGet_1142
.LvarGet_1126:
    movs r1, #0xb9
    lsls r1, r1, #1
    mov r3, sp
    movs r0, #0
    strb r0, [r3]
    adds r0, r2, #0
    movs r2, #0x1f
    b .LvarGet_131E
.LvarGet_1136:
    ldr r1, .LvarGet_114C @ =0x00000173
    mov r3, sp
    movs r0, #0
    strb r0, [r3]
    adds r0, r2, #0
    movs r2, #0x1f
.LvarGet_1142:
    movs r3, #6
    bl func_080455D8
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_114C: .word 0x00000173
.LvarGet_1150:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x71
    movs r2, #0x13
    b .LvarGet_12BA
.LvarGet_115E:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x72
    movs r2, #0x13
    b .LvarGet_12D0
.LvarGet_116C:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x73
    movs r2, #0x13
    b .LvarGet_12E6
.LvarGet_117A:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x74
    movs r2, #0x13
    b .LvarGet_12FC
.LvarGet_1188:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x75
    movs r2, #0x13
    b .LvarGet_131E
.LvarGet_1196:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x76
    movs r2, #0x13
    b .LvarGet_131E
.LvarGet_11A4:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x77
    movs r2, #0x13
    b .LvarGet_131E
.LvarGet_11B2:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x7a
    movs r2, #3
    b .LvarGet_12BA
.LvarGet_11C0:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x7b
    movs r2, #3
    b .LvarGet_12D0
.LvarGet_11CE:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x7c
    movs r2, #3
    b .LvarGet_12E6
.LvarGet_11DC:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x7d
    movs r2, #3
    b .LvarGet_12FC
.LvarGet_11EA:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x7e
    movs r2, #3
    b .LvarGet_131E
.LvarGet_11F8:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x7f
    movs r2, #3
    b .LvarGet_131E
.LvarGet_1206:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x82
    movs r2, #0x19
    b .LvarGet_12BA
.LvarGet_1214:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x83
    movs r2, #0x19
    b .LvarGet_12D0
.LvarGet_1222:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x84
    movs r2, #0x19
    b .LvarGet_12E6
.LvarGet_1230:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x85
    movs r2, #0x19
    b .LvarGet_12FC
.LvarGet_123E:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x86
    movs r2, #0x19
    b .LvarGet_131E
.LvarGet_124C:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x87
    movs r2, #0x19
    b .LvarGet_131E
.LvarGet_125A:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x8a
    movs r2, #0xc
    b .LvarGet_12BA
.LvarGet_1268:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x8b
    movs r2, #0xc
    b .LvarGet_12D0
.LvarGet_1276:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x8c
    movs r2, #0xc
    b .LvarGet_12E6
.LvarGet_1284:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x8d
    movs r2, #0xc
    b .LvarGet_12FC
.LvarGet_1292:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x8e
    movs r2, #0xc
    b .LvarGet_131E
.LvarGet_12A0:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x8f
    movs r2, #0xc
    b .LvarGet_131E
.LvarGet_12AE:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x92
.LvarGet_12B8:
    movs r2, #0x15
.LvarGet_12BA:
    movs r3, #1
    bl func_080455D8
    bl .LvarGetReturn
.LvarGet_12C4:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x93
.LvarGet_12CE:
    movs r2, #0x15
.LvarGet_12D0:
    movs r3, #2
    bl func_080455D8
    bl .LvarGetReturn
.LvarGet_12DA:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x94
.LvarGet_12E4:
    movs r2, #0x15
.LvarGet_12E6:
    movs r3, #3
    bl func_080455D8
    bl .LvarGetReturn
.LvarGet_12F0:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x95
.LvarGet_12FA:
    movs r2, #0x15
.LvarGet_12FC:
    movs r3, #4
    bl func_080455D8
    bl .LvarGetReturn
.LvarGet_1306:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x96
    b .LvarGet_131C
.LvarGet_1312:
    mov r1, sp
    movs r0, #1
    strb r0, [r1]
    adds r0, r2, #0
    movs r1, #0x97
.LvarGet_131C:
    movs r2, #0x15
.LvarGet_131E:
    movs r3, #5
    bl func_080455D8
    bl .LvarGetReturn
.LvarGet_1328:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1338 @ =0x0000215A
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_1338: .word 0x0000215A
.LvarGet_133C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_134C @ =0x0000215A
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_134C: .word 0x0000215A
.LvarGet_1350:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1360 @ =0x0000215B
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1360: .word 0x0000215B
.LvarGet_1364:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1374 @ =0x0000215B
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_1374: .word 0x0000215B
.LvarGet_1378:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1388 @ =0x0000215C
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_1388: .word 0x0000215C
.LvarGet_138C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_139C @ =0x0000215A
    bl .LvarGet_35BA
    .align 2, 0
.LvarGet_139C: .word 0x0000215A
.LvarGet_13A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_13B0 @ =0x0000215A
    bl .LvarGet_3652
    .align 2, 0
.LvarGet_13B0: .word 0x0000215A
.LvarGet_13B4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_13C4 @ =0x0000215A
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_13C4: .word 0x0000215A
.LvarGet_13C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_13D8 @ =0x0000215B
    bl .LvarGet_35BA
    .align 2, 0
.LvarGet_13D8: .word 0x0000215B
.LvarGet_13DC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_13EC @ =0x0000215B
    bl .LvarGet_3302
    .align 2, 0
.LvarGet_13EC: .word 0x0000215B
.LvarGet_13F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1400 @ =0x0000215B
    bl .LvarGet_363A
    .align 2, 0
.LvarGet_1400: .word 0x0000215B
.LvarGet_1404:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1414 @ =0x0000215B
    bl .LvarGet_36BA
    .align 2, 0
.LvarGet_1414: .word 0x0000215B
.LvarGet_1418:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1428 @ =0x0000215C
    bl .LvarGet_35BA
    .align 2, 0
.LvarGet_1428: .word 0x0000215C
.LvarGet_142C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_143C @ =0x0000215C
    bl .LvarGet_3652
    .align 2, 0
.LvarGet_143C: .word 0x0000215C
.LvarGet_1440:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1450 @ =0x0000215C
    bl .LvarGet_36BA
    .align 2, 0
.LvarGet_1450: .word 0x0000215C
.LvarGet_1454:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1464 @ =0x0000215C
    bl .LvarGet_360A
    .align 2, 0
.LvarGet_1464: .word 0x0000215C
.LvarGet_1468:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1478 @ =0x0000215D
    bl .LvarGet_3302
    .align 2, 0
.LvarGet_1478: .word 0x0000215D
.LvarGet_147C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_148C @ =0x0000215D
    bl .LvarGet_3652
    .align 2, 0
.LvarGet_148C: .word 0x0000215D
.LvarGet_1490:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_14A0 @ =0x0000215C
    bl .LvarGet_366A
    .align 2, 0
.LvarGet_14A0: .word 0x0000215C
.LvarGet_14A4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_14B4 @ =0x0000215C
    bl .LvarGet_36D2
    .align 2, 0
.LvarGet_14B4: .word 0x0000215C
.LvarGet_14B8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_14C8 @ =0x0000215D
    bl .LvarGet_35BA
    .align 2, 0
.LvarGet_14C8: .word 0x0000215D
.LvarGet_14CC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_14DC @ =0x0000215D
    bl .LvarGet_363A
    .align 2, 0
.LvarGet_14DC: .word 0x0000215D
.LvarGet_14E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_14F0 @ =0x0000215D
    bl .LvarGet_366A
    .align 2, 0
.LvarGet_14F0: .word 0x0000215D
.LvarGet_14F4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1504 @ =0x0000215D
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1504: .word 0x0000215D
.LvarGet_1508:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1518 @ =0x0000215C
    bl .LvarGet_280E
    .align 2, 0
.LvarGet_1518: .word 0x0000215C
.LvarGet_151C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_152C @ =0x0000215E
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_152C: .word 0x0000215E
.LvarGet_1530:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1540 @ =0x0000215E
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1540: .word 0x0000215E
.LvarGet_1544:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1554 @ =0x0000215E
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1554: .word 0x0000215E
.LvarGet_1558:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1568 @ =0x0000215E
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_1568: .word 0x0000215E
.LvarGet_156C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_157C @ =0x0000215F
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_157C: .word 0x0000215F
.LvarGet_1580:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1590 @ =0x0000215F
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1590: .word 0x0000215F
.LvarGet_1594:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_15A4 @ =0x0000215F
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_15A4: .word 0x0000215F
.LvarGet_15A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_15C4 @ =0x0000215F
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #7
    ldr r1, .LvarGet_15C8 @ =0x00002160
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #1
    bl .LvarGet_3170
    .align 2, 0
.LvarGet_15C4: .word 0x0000215F
.LvarGet_15C8: .word 0x00002160
.LvarGet_15CC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_15DC @ =0x00002160
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_15DC: .word 0x00002160
.LvarGet_15E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_15F0 @ =0x00002160
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_15F0: .word 0x00002160
.LvarGet_15F4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1604 @ =0x00002160
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1604: .word 0x00002160
.LvarGet_1608:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1618 @ =0x00002160
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_1618: .word 0x00002160
.LvarGet_161C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_162C @ =0x00002161
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_162C: .word 0x00002161
.LvarGet_1630:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1640 @ =0x00002161
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1640: .word 0x00002161
.LvarGet_1644:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1654 @ =0x00002161
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1654: .word 0x00002161
.LvarGet_1658:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1668 @ =0x00002160
    bl .LvarGet_280E
    .align 2, 0
.LvarGet_1668: .word 0x00002160
.LvarGet_166C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_167C @ =0x00002162
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_167C: .word 0x00002162
.LvarGet_1680:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1690 @ =0x00002162
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1690: .word 0x00002162
.LvarGet_1694:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_16A4 @ =0x00002162
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_16A4: .word 0x00002162
.LvarGet_16A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_16B8 @ =0x00002162
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_16B8: .word 0x00002162
.LvarGet_16BC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_16CC @ =0x00002163
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_16CC: .word 0x00002163
.LvarGet_16D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_16E0 @ =0x00002163
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_16E0: .word 0x00002163
.LvarGet_16E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_16F4 @ =0x00002163
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_16F4: .word 0x00002163
.LvarGet_16F8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1714 @ =0x00002163
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #7
    ldr r1, .LvarGet_1718 @ =0x00002164
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #1
    bl .LvarGet_3170
    .align 2, 0
.LvarGet_1714: .word 0x00002163
.LvarGet_1718: .word 0x00002164
.LvarGet_171C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_172C @ =0x00002164
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_172C: .word 0x00002164
.LvarGet_1730:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1740 @ =0x00002164
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1740: .word 0x00002164
.LvarGet_1744:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1754 @ =0x00002164
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1754: .word 0x00002164
.LvarGet_1758:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1768 @ =0x00002164
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_1768: .word 0x00002164
.LvarGet_176C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_177C @ =0x00002165
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_177C: .word 0x00002165
.LvarGet_1780:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1790 @ =0x00002165
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1790: .word 0x00002165
.LvarGet_1794:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_17A4 @ =0x00002165
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_17A4: .word 0x00002165
.LvarGet_17A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_17B8 @ =0x00002164
    bl .LvarGet_280E
    .align 2, 0
.LvarGet_17B8: .word 0x00002164
.LvarGet_17BC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_17CC @ =0x00002166
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_17CC: .word 0x00002166
.LvarGet_17D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_17E0 @ =0x00002166
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_17E0: .word 0x00002166
.LvarGet_17E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_17F4 @ =0x00002166
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_17F4: .word 0x00002166
.LvarGet_17F8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1808 @ =0x00002166
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_1808: .word 0x00002166
.LvarGet_180C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_181C @ =0x00002167
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_181C: .word 0x00002167
.LvarGet_1820:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1830 @ =0x00002167
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1830: .word 0x00002167
.LvarGet_1834:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1844 @ =0x00002167
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1844: .word 0x00002167
.LvarGet_1848:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1864 @ =0x00002167
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #7
    ldr r1, .LvarGet_1868 @ =0x00002168
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #1
    bl .LvarGet_3170
    .align 2, 0
.LvarGet_1864: .word 0x00002167
.LvarGet_1868: .word 0x00002168
.LvarGet_186C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_187C @ =0x00002168
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_187C: .word 0x00002168
.LvarGet_1880:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1890 @ =0x00002168
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1890: .word 0x00002168
.LvarGet_1894:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_18A4 @ =0x00002168
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_18A4: .word 0x00002168
.LvarGet_18A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_18B8 @ =0x00002168
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_18B8: .word 0x00002168
.LvarGet_18BC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_18CC @ =0x00002169
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_18CC: .word 0x00002169
.LvarGet_18D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_18E0 @ =0x00002169
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_18E0: .word 0x00002169
.LvarGet_18E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_18F4 @ =0x00002169
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_18F4: .word 0x00002169
.LvarGet_18F8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1908 @ =0x00002168
    bl .LvarGet_280E
    .align 2, 0
.LvarGet_1908: .word 0x00002168
.LvarGet_190C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_191C @ =0x0000216A
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_191C: .word 0x0000216A
.LvarGet_1920:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1930 @ =0x0000216A
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1930: .word 0x0000216A
.LvarGet_1934:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1944 @ =0x0000216A
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1944: .word 0x0000216A
.LvarGet_1948:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1958 @ =0x0000216A
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_1958: .word 0x0000216A
.LvarGet_195C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_196C @ =0x0000216B
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_196C: .word 0x0000216B
.LvarGet_1970:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1980 @ =0x0000216B
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1980: .word 0x0000216B
.LvarGet_1984:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1994 @ =0x0000216B
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1994: .word 0x0000216B
.LvarGet_1998:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_19B4 @ =0x0000216B
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #7
    ldr r1, .LvarGet_19B8 @ =0x0000216C
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #1
    bl .LvarGet_3170
    .align 2, 0
.LvarGet_19B4: .word 0x0000216B
.LvarGet_19B8: .word 0x0000216C
.LvarGet_19BC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_19CC @ =0x0000216C
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_19CC: .word 0x0000216C
.LvarGet_19D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_19E0 @ =0x0000216C
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_19E0: .word 0x0000216C
.LvarGet_19E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_19F4 @ =0x0000216C
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_19F4: .word 0x0000216C
.LvarGet_19F8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1A08 @ =0x0000216C
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_1A08: .word 0x0000216C
.LvarGet_1A0C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1A1C @ =0x0000216D
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_1A1C: .word 0x0000216D
.LvarGet_1A20:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1A30 @ =0x0000216D
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1A30: .word 0x0000216D
.LvarGet_1A34:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1A44 @ =0x0000216D
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1A44: .word 0x0000216D
.LvarGet_1A48:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1A58 @ =0x0000216C
    bl .LvarGet_280E
    .align 2, 0
.LvarGet_1A58: .word 0x0000216C
.LvarGet_1A5C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1A6C @ =0x0000216E
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_1A6C: .word 0x0000216E
.LvarGet_1A70:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1A80 @ =0x0000216E
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1A80: .word 0x0000216E
.LvarGet_1A84:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1AA8 @ =0x0000216F
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #4
    ldr r1, .LvarGet_1AAC @ =0x00002170
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #7
    ands r0, r1
    lsls r0, r0, #4
    orrs r0, r2
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_1AA8: .word 0x0000216F
.LvarGet_1AAC: .word 0x00002170
.LvarGet_1AB0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1AC0 @ =0x00002170
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1AC0: .word 0x00002170
.LvarGet_1AC4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1AD4 @ =0x00002170
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1AD4: .word 0x00002170
.LvarGet_1AD8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1AE8 @ =0x00002170
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_1AE8: .word 0x00002170
.LvarGet_1AEC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1AFC @ =0x00002171
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_1AFC: .word 0x00002171
.LvarGet_1B00:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1B10 @ =0x00002171
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1B10: .word 0x00002171
.LvarGet_1B14:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1B24 @ =0x00002171
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1B24: .word 0x00002171
.LvarGet_1B28:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1B38 @ =0x00002171
    bl .LvarGet_360A
    .align 2, 0
.LvarGet_1B38: .word 0x00002171
.LvarGet_1B3C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1B4C @ =0x00002172
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_1B4C: .word 0x00002172
.LvarGet_1B50:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1B60 @ =0x00002172
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_1B60: .word 0x00002172
.LvarGet_1B64:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1B74 @ =0x00002172
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_1B74: .word 0x00002172
.LvarGet_1B78:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1B88 @ =0x00002172
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_1B88: .word 0x00002172
.LvarGet_1B8C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1B9C @ =0x00002173
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_1B9C: .word 0x00002173
.LvarGet_1BA0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1BB0 @ =0x00002173
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_1BB0: .word 0x00002173
.LvarGet_1BB4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1BC4 @ =0x00002173
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_1BC4: .word 0x00002173
.LvarGet_1BC8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1BD8 @ =0x00002173
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_1BD8: .word 0x00002173
.LvarGet_1BDC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1BEC @ =0x00002174
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_1BEC: .word 0x00002174
.LvarGet_1BF0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1C00 @ =0x00002174
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_1C00: .word 0x00002174
.LvarGet_1C04:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1C14 @ =0x00002174
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_1C14: .word 0x00002174
.LvarGet_1C18:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1C28 @ =0x00002174
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_1C28: .word 0x00002174
.LvarGet_1C2C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1C3C @ =0x00002175
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_1C3C: .word 0x00002175
.LvarGet_1C40:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1C50 @ =0x00002175
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_1C50: .word 0x00002175
.LvarGet_1C54:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1C64 @ =0x00002175
    bl .LvarGet_366A
    .align 2, 0
.LvarGet_1C64: .word 0x00002175
.LvarGet_1C68:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1C78 @ =0x00002175
    bl .LvarGet_36BA
    .align 2, 0
.LvarGet_1C78: .word 0x00002175
.LvarGet_1C7C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1C8C @ =0x00002175
    bl .LvarGet_36D2
    .align 2, 0
.LvarGet_1C8C: .word 0x00002175
.LvarGet_1C90:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1CA0 @ =0x00002175
    bl .LvarGet_360A
    .align 2, 0
.LvarGet_1CA0: .word 0x00002175
.LvarGet_1CA4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1CB4 @ =0x00002176
    bl .LvarGet_35BA
    .align 2, 0
.LvarGet_1CB4: .word 0x00002176
.LvarGet_1CB8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1CC8 @ =0x00002176
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_1CC8: .word 0x00002176
.LvarGet_1CCC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1CDC @ =0x00002176
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1CDC: .word 0x00002176
.LvarGet_1CE0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1CF0 @ =0x00002176
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1CF0: .word 0x00002176
.LvarGet_1CF4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1D04 @ =0x00002176
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_1D04: .word 0x00002176
.LvarGet_1D08:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1D18 @ =0x00002177
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_1D18: .word 0x00002177
.LvarGet_1D1C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1D2C @ =0x00002177
    bl .LvarGet_3652
    .align 2, 0
.LvarGet_1D2C: .word 0x00002177
.LvarGet_1D30:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1D40 @ =0x00002177
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_1D40: .word 0x00002177
.LvarGet_1D44:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1D54 @ =0x00002177
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_1D54: .word 0x00002177
.LvarGet_1D58:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1D68 @ =0x00002178
    bl .LvarGet_35BA
    .align 2, 0
.LvarGet_1D68: .word 0x00002178
.LvarGet_1D6C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1D7C @ =0x00002178
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_1D7C: .word 0x00002178
.LvarGet_1D80:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1D98 @ =0x00002178
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1a
    lsrs r0, r0, #0x1d
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_1D98: .word 0x00002178
.LvarGet_1D9C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1DAC @ =0x00002178
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_1DAC: .word 0x00002178
.LvarGet_1DB0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1DC0 @ =0x00002179
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_1DC0: .word 0x00002179
.LvarGet_1DC4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1DD4 @ =0x00002179
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_1DD4: .word 0x00002179
.LvarGet_1DD8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1DE8 @ =0x00002179
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_1DE8: .word 0x00002179
.LvarGet_1DEC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1DF8 @ =0x00002178
    b .LvarGet_230E
    .align 2, 0
.LvarGet_1DF8: .word 0x00002178
.LvarGet_1DFC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1E0C @ =0x0000217A
    bl .LvarGet_363A
    .align 2, 0
.LvarGet_1E0C: .word 0x0000217A
.LvarGet_1E10:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1E20 @ =0x0000217A
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1E20: .word 0x0000217A
.LvarGet_1E24:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1E34 @ =0x0000217A
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1E34: .word 0x0000217A
.LvarGet_1E38:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1E48 @ =0x0000217A
    bl .LvarGet_360A
    .align 2, 0
.LvarGet_1E48: .word 0x0000217A
.LvarGet_1E4C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1E64 @ =0x0000217B
    adds r0, r0, r2
    ldrb r0, [r0]

.LvarGetMaskFiveBits:
    lsls r0, r0, #0x1b
    lsrs r0, r0, #0x1b
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_1E64: .word 0x0000217B
.LvarGet_1E68:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1E78 @ =0x0000217B
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1E78: .word 0x0000217B
.LvarGet_1E7C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1E98 @ =0x0000217B
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #7
    ldr r1, .LvarGet_1E9C @ =0x0000217C
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #1
    bl .LvarGet_3170
    .align 2, 0
.LvarGet_1E98: .word 0x0000217B
.LvarGet_1E9C: .word 0x0000217C
.LvarGet_1EA0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1EB0 @ =0x0000217C
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_1EB0: .word 0x0000217C
.LvarGet_1EB4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1EC4 @ =0x0000217C
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_1EC4: .word 0x0000217C
.LvarGet_1EC8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1ED8 @ =0x0000217C
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_1ED8: .word 0x0000217C
.LvarGet_1EDC:
    @ Variable 275: farm save +0x217C bit 7.  Ellen's yarn-gift script
    @ requires it to be clear, but no vanilla script identifies its owner.
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1EEC @ =0x0000217C
    bl .LvarGet_360A
    .align 2, 0
.LvarGet_1EEC: .word 0x0000217C
.LvarGet_1EF0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1F00 @ =0x0000217D
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_1F00: .word 0x0000217D
.LvarGet_1F04:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1F14 @ =0x0000217D
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_1F14: .word 0x0000217D
.LvarGet_1F18:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1F28 @ =0x0000217D
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_1F28: .word 0x0000217D
.LvarGet_1F2C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1F3C @ =0x0000217D
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_1F3C: .word 0x0000217D
.LvarGet_1F40:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1F50 @ =0x0000217E
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_1F50: .word 0x0000217E
.LvarGet_1F54:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1F64 @ =0x0000217E
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_1F64: .word 0x0000217E
.LvarGet_1F68:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1F78 @ =0x0000217E
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_1F78: .word 0x0000217E
.LvarGet_1F7C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1F8C @ =0x0000217E
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_1F8C: .word 0x0000217E
.LvarGet_1F90:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1FA0 @ =0x0000217F
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_1FA0: .word 0x0000217F
.LvarGet_1FA4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1FB4 @ =0x0000217F
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_1FB4: .word 0x0000217F
.LvarGet_1FB8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1FC8 @ =0x0000217F
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_1FC8: .word 0x0000217F
.LvarGet_1FCC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_1FDC @ =0x0000217F
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_1FDC: .word 0x0000217F
.LvarGet_1FE0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0x86
    lsls r2, r2, #6
    bl .LvarGet_3622
.LvarGet_1FF0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0x86
    lsls r2, r2, #6
    bl .LvarGet_3552
.LvarGet_2000:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0x86
    lsls r2, r2, #6
    bl .LvarGet_356A
.LvarGet_2010:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0x86
    lsls r2, r2, #6
    bl .LvarGet_352A
.LvarGet_2020:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2030 @ =0x00002181
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2030: .word 0x00002181
.LvarGet_2034:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2044 @ =0x00002181
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_2044: .word 0x00002181
.LvarGet_2048:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2058 @ =0x00002181
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_2058: .word 0x00002181
.LvarGet_205C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_206C @ =0x00002181
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_206C: .word 0x00002181
.LvarGet_2070:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2080 @ =0x00002182
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2080: .word 0x00002182
.LvarGet_2084:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2094 @ =0x00002182
    bl .LvarGet_363A
    .align 2, 0
.LvarGet_2094: .word 0x00002182
.LvarGet_2098:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_20A8 @ =0x00002182
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_20A8: .word 0x00002182
.LvarGet_20AC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_20BC @ =0x00002182
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_20BC: .word 0x00002182
.LvarGet_20C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_20D0 @ =0x00002182
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_20D0: .word 0x00002182
.LvarGet_20D4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_20E4 @ =0x00002183
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_20E4: .word 0x00002183
.LvarGet_20E8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_20F8 @ =0x00002183
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_20F8: .word 0x00002183
.LvarGet_20FC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_210C @ =0x00002183
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_210C: .word 0x00002183
.LvarGet_2110:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_212C @ =0x00002183
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #7
    ldr r1, .LvarGet_2130 @ =0x00002184
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #1
    bl .LvarGet_3170
    .align 2, 0
.LvarGet_212C: .word 0x00002183
.LvarGet_2130: .word 0x00002184
.LvarGet_2134:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2144 @ =0x00002184
    bl .LvarGet_3302
    .align 2, 0
.LvarGet_2144: .word 0x00002184
.LvarGet_2148:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2158 @ =0x00002184
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_2158: .word 0x00002184
.LvarGet_215C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_216C @ =0x00002184
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_216C: .word 0x00002184
.LvarGet_2170:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2180 @ =0x00002184
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2180: .word 0x00002184
.LvarGet_2184:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2194 @ =0x00002185
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2194: .word 0x00002185
.LvarGet_2198:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_21A8 @ =0x00002185
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_21A8: .word 0x00002185
.LvarGet_21AC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_21BC @ =0x00002185
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_21BC: .word 0x00002185
.LvarGet_21C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_21D0 @ =0x00002185
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_21D0: .word 0x00002185
.LvarGet_21D4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_21E4 @ =0x00002186
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_21E4: .word 0x00002186
.LvarGet_21E8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2200 @ =0x00002186
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1b
    lsrs r0, r0, #0x1d
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_2200: .word 0x00002186
.LvarGet_2204:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2214 @ =0x00002186
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_2214: .word 0x00002186
.LvarGet_2218:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2228 @ =0x00002186
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_2228: .word 0x00002186
.LvarGet_222C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_223C @ =0x00002187
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_223C: .word 0x00002187
.LvarGet_2240:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2250 @ =0x00002187
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_2250: .word 0x00002187
.LvarGet_2254:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2264 @ =0x00002187
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_2264: .word 0x00002187
.LvarGet_2268:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2284 @ =0x00002187
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #7
    ldr r1, .LvarGet_2288 @ =0x00002188
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #1
    bl .LvarGet_3170
    .align 2, 0
.LvarGet_2284: .word 0x00002187
.LvarGet_2288: .word 0x00002188
.LvarGet_228C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_229C @ =0x00002188
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_229C: .word 0x00002188
.LvarGet_22A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_22B0 @ =0x00002188
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_22B0: .word 0x00002188
.LvarGet_22B4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_22C4 @ =0x00002188
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_22C4: .word 0x00002188
.LvarGet_22C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_22D8 @ =0x00002188
    bl .LvarGet_2AA2
    .align 2, 0
.LvarGet_22D8: .word 0x00002188
.LvarGet_22DC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_22EC @ =0x00002189
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_22EC: .word 0x00002189
.LvarGet_22F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2300 @ =0x00002189
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_2300: .word 0x00002189
.LvarGet_2304:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_231C @ =0x00002188
.LvarGet_230E:
    adds r0, r0, r2
    ldr r0, [r0]
    lsls r0, r0, #0xe
    lsrs r0, r0, #0x1c
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_231C: .word 0x00002188
.LvarGet_2320:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2330 @ =0x0000218A
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_2330: .word 0x0000218A
.LvarGet_2334:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2344 @ =0x0000218A
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_2344: .word 0x0000218A
.LvarGet_2348:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2358 @ =0x0000218A
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2358: .word 0x0000218A
.LvarGet_235C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_236C @ =0x0000218B
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_236C: .word 0x0000218B
.LvarGet_2370:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2380 @ =0x0000218B
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_2380: .word 0x0000218B
.LvarGet_2384:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_23A8 @ =0x0000218B
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #5
    ldr r1, .LvarGet_23AC @ =0x0000218C
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #1
    ands r0, r1
    lsls r0, r0, #3
    orrs r0, r2
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_23A8: .word 0x0000218B
.LvarGet_23AC: .word 0x0000218C
.LvarGet_23B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_23C0 @ =0x0000218C
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_23C0: .word 0x0000218C
.LvarGet_23C4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_23D4 @ =0x0000218C
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_23D4: .word 0x0000218C
.LvarGet_23D8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_23E8 @ =0x0000218C
    bl .LvarGet_2D56
    .align 2, 0
.LvarGet_23E8: .word 0x0000218C
.LvarGet_23EC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_23FC @ =0x0000218C
    bl .LvarGet_2D1A
    .align 2, 0
.LvarGet_23FC: .word 0x0000218C
.LvarGet_2400:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2410 @ =0x0000218D
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_2410: .word 0x0000218D
.LvarGet_2414:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2424 @ =0x0000218D
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_2424: .word 0x0000218D
.LvarGet_2428:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2440 @ =0x0000218C
    adds r0, r0, r2
    ldr r0, [r0]
    lsls r0, r0, #0xf
    lsrs r0, r0, #0x1c
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_2440: .word 0x0000218C
.LvarGet_2444:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2454 @ =0x0000218E
    bl .LvarGet_305A
    .align 2, 0
.LvarGet_2454: .word 0x0000218E
.LvarGet_2458:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2468 @ =0x0000218E
    bl .LvarGet_2DA6
    .align 2, 0
.LvarGet_2468: .word 0x0000218E
.LvarGet_246C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_247C @ =0x0000218E
    bl .LvarGet_36BA
    .align 2, 0
.LvarGet_247C: .word 0x0000218E
.LvarGet_2480:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2490 @ =0x0000218E
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2490: .word 0x0000218E
.LvarGet_2494:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_24A4 @ =0x0000218F
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_24A4: .word 0x0000218F
.LvarGet_24A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_24B8 @ =0x0000218F
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_24B8: .word 0x0000218F
.LvarGet_24BC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_24CC @ =0x0000218F
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_24CC: .word 0x0000218F
.LvarGet_24D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_24E0 @ =0x0000218F
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_24E0: .word 0x0000218F
.LvarGet_24E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_24F4 @ =0x00002190
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_24F4: .word 0x00002190
.LvarGet_24F8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2508 @ =0x00002190
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_2508: .word 0x00002190
.LvarGet_250C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_251C @ =0x00002190
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_251C: .word 0x00002190
.LvarGet_2520:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2530 @ =0x00002190
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2530: .word 0x00002190
.LvarGet_2534:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2544 @ =0x00002191
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2544: .word 0x00002191
.LvarGet_2548:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2558 @ =0x00002191
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_2558: .word 0x00002191
.LvarGet_255C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_256C @ =0x00002191
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_256C: .word 0x00002191
.LvarGet_2570:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2580 @ =0x00002191
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2580: .word 0x00002191
.LvarGet_2584:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2594 @ =0x00002192
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2594: .word 0x00002192
.LvarGet_2598:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_25A8 @ =0x00002192
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_25A8: .word 0x00002192
.LvarGet_25AC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_25BC @ =0x00002192
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_25BC: .word 0x00002192
.LvarGet_25C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_25D0 @ =0x00002192
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_25D0: .word 0x00002192
.LvarGet_25D4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_25E4 @ =0x00002193
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_25E4: .word 0x00002193
.LvarGet_25E8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_25F8 @ =0x00002193
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_25F8: .word 0x00002193
.LvarGet_25FC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_260C @ =0x00002193
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_260C: .word 0x00002193
.LvarGet_2610:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2620 @ =0x00002193
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2620: .word 0x00002193
.LvarGet_2624:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2634 @ =0x00002194
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2634: .word 0x00002194
.LvarGet_2638:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2648 @ =0x00002194
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_2648: .word 0x00002194
.LvarGet_264C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_265C @ =0x00002194
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_265C: .word 0x00002194
.LvarGet_2660:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2670 @ =0x00002194
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2670: .word 0x00002194
.LvarGet_2674:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2684 @ =0x00002195
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2684: .word 0x00002195
.LvarGet_2688:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2698 @ =0x00002195
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2698: .word 0x00002195
.LvarGet_269C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_26AC @ =0x00002196
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_26AC: .word 0x00002196
.LvarGet_26B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_26C0 @ =0x00002196
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_26C0: .word 0x00002196
.LvarGet_26C4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_26D4 @ =0x00002196
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_26D4: .word 0x00002196
.LvarGet_26D8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_26E8 @ =0x00002196
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_26E8: .word 0x00002196
.LvarGet_26EC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_26FC @ =0x00002197
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_26FC: .word 0x00002197
.LvarGet_2700:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2710 @ =0x00002197
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_2710: .word 0x00002197
.LvarGet_2714:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2724 @ =0x00002197
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_2724: .word 0x00002197
.LvarGet_2728:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2738 @ =0x00002197
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2738: .word 0x00002197
.LvarGet_273C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_274C @ =0x00002198
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_274C: .word 0x00002198
.LvarGet_2750:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2760 @ =0x00002198
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_2760: .word 0x00002198
.LvarGet_2764:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2774 @ =0x00002198
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_2774: .word 0x00002198
.LvarGet_2778:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2788 @ =0x00002198
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2788: .word 0x00002198
.LvarGet_278C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_279C @ =0x00002199
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_279C: .word 0x00002199
.LvarGet_27A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_27B0 @ =0x00002199
    bl .LvarGet_363A
    .align 2, 0
.LvarGet_27B0: .word 0x00002199
.LvarGet_27B4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_27C4 @ =0x00002199
    bl .LvarGet_3652
    .align 2, 0
.LvarGet_27C4: .word 0x00002199
.LvarGet_27C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_27D8 @ =0x00002199
    bl .LvarGet_366A
    .align 2, 0
.LvarGet_27D8: .word 0x00002199
.LvarGet_27DC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_27EC @ =0x00002199
    bl .LvarGet_36BA
    .align 2, 0
.LvarGet_27EC: .word 0x00002199
.LvarGet_27F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2800 @ =0x00002199
    bl .LvarGet_36D2
    .align 2, 0
.LvarGet_2800: .word 0x00002199
.LvarGet_2804:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_281C @ =0x00002198
.LvarGet_280E:
    adds r0, r0, r2
    ldr r0, [r0]
    lsls r0, r0, #0xf
    lsrs r0, r0, #0x1e
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_281C: .word 0x00002198
.LvarGet_2820:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2830 @ =0x0000219A
    bl .LvarGet_3302
    .align 2, 0
.LvarGet_2830: .word 0x0000219A
.LvarGet_2834:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2844 @ =0x0000219A
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_2844: .word 0x0000219A
.LvarGet_2848:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2858 @ =0x0000219A
    bl .LvarGet_366A
    .align 2, 0
.LvarGet_2858: .word 0x0000219A
.LvarGet_285C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2868 @ =0x0000219A
    b .LvarGet_2D56
    .align 2, 0
.LvarGet_2868: .word 0x0000219A
.LvarGet_286C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2878 @ =0x0000219A
    b .LvarGet_2D1A
    .align 2, 0
.LvarGet_2878: .word 0x0000219A
.LvarGet_287C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2894 @ =0x0000219B
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1c
    lsrs r0, r0, #0x1d
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_2894: .word 0x0000219B
.LvarGet_2898:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_28A8 @ =0x0000219B
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_28A8: .word 0x0000219B
.LvarGet_28AC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_28BC @ =0x0000219B
    bl .LvarGet_36D2
    .align 2, 0
.LvarGet_28BC: .word 0x0000219B
.LvarGet_28C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_28DC @ =0x0000219B
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #7
    ldr r1, .LvarGet_28E0 @ =0x0000219C
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #3
    bl .LvarGet_3170
    .align 2, 0
.LvarGet_28DC: .word 0x0000219B
.LvarGet_28E0: .word 0x0000219C
.LvarGet_28E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_28F4 @ =0x0000219C
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_28F4: .word 0x0000219C
.LvarGet_28F8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2908 @ =0x0000219C
    bl .LvarGet_366A
    .align 2, 0
.LvarGet_2908: .word 0x0000219C
.LvarGet_290C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2918 @ =0x0000219C
    b .LvarGet_2D56
    .align 2, 0
.LvarGet_2918: .word 0x0000219C
.LvarGet_291C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_292C @ =0x0000219C
    bl .LvarGet_360A
    .align 2, 0
.LvarGet_292C: .word 0x0000219C
.LvarGet_2930:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2940 @ =0x0000219D
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2940: .word 0x0000219D
.LvarGet_2944:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2954 @ =0x0000219D
    bl .LvarGet_363A
    .align 2, 0
.LvarGet_2954: .word 0x0000219D
.LvarGet_2958:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2964 @ =0x0000219D
    b .LvarGet_2DA6
    .align 2, 0
.LvarGet_2964: .word 0x0000219D
.LvarGet_2968:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2978 @ =0x0000219D
    bl .LvarGet_36BA
    .align 2, 0
.LvarGet_2978: .word 0x0000219D
.LvarGet_297C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_298C @ =0x0000219D
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_298C: .word 0x0000219D
.LvarGet_2990:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_29A0 @ =0x0000219E
    bl .LvarGet_35BA
    .align 2, 0
.LvarGet_29A0: .word 0x0000219E
.LvarGet_29A4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_29B0 @ =0x0000219E
    b .LvarGet_305A
    .align 2, 0
.LvarGet_29B0: .word 0x0000219E
.LvarGet_29B4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_29C4 @ =0x0000219E
    bl .LvarGet_3652
    .align 2, 0
.LvarGet_29C4: .word 0x0000219E
.LvarGet_29C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_29D8 @ =0x0000219E
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_29D8: .word 0x0000219E
.LvarGet_29DC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_29E8 @ =0x0000219E
    b .LvarGet_3044
    .align 2, 0
.LvarGet_29E8: .word 0x0000219E
.LvarGet_29EC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_29F8 @ =0x0000219F
    b .LvarGet_305A
    .align 2, 0
.LvarGet_29F8: .word 0x0000219F
.LvarGet_29FC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2A0C @ =0x0000219F
    bl .LvarGet_3652
    .align 2, 0
.LvarGet_2A0C: .word 0x0000219F
.LvarGet_2A10:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2A20 @ =0x0000219F
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_2A20: .word 0x0000219F
.LvarGet_2A24:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2A34 @ =0x0000219F
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2A34: .word 0x0000219F
.LvarGet_2A38:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2A48 @ =0x000021A0
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2A48: .word 0x000021A0
.LvarGet_2A4C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2A5C @ =0x000021A0
    bl .LvarGet_363A
    .align 2, 0
.LvarGet_2A5C: .word 0x000021A0
.LvarGet_2A60:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2A70 @ =0x000021A0
    bl .LvarGet_3652
    .align 2, 0
.LvarGet_2A70: .word 0x000021A0
.LvarGet_2A74:
    @ Variable 423: farm save +0x21A0 bit 4.  The daily world-state reset
    @ clears it; adjacency does not establish a Harvest Festival meaning.
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2A84 @ =0x000021A0
    bl .LvarGet_366A
    .align 2, 0
.LvarGet_2A84: .word 0x000021A0
.LvarGet_2A88:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2A94 @ =0x000021A0
    b .LvarGet_2D56
    .align 2, 0
.LvarGet_2A94: .word 0x000021A0
.LvarGet_2A98:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2AB0 @ =0x000021CA
.LvarGet_2AA2:
    adds r0, r0, r2
    ldrh r0, [r0]
    lsls r0, r0, #0x16
    lsrs r0, r0, #0x1d
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_2AB0: .word 0x000021CA
.LvarGet_2AB4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2AC4 @ =0x000021A1
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2AC4: .word 0x000021A1
.LvarGet_2AC8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2AD8 @ =0x000021A1
    bl .LvarGet_363A
    .align 2, 0
.LvarGet_2AD8: .word 0x000021A1
.LvarGet_2ADC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2AE8 @ =0x000021A1
    b .LvarGet_2DA6
    .align 2, 0
.LvarGet_2AE8: .word 0x000021A1
.LvarGet_2AEC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2AFC @ =0x000021A1
    bl .LvarGet_36BA
    .align 2, 0
.LvarGet_2AFC: .word 0x000021A1
.LvarGet_2B00:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2B10 @ =0x000021A1
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2B10: .word 0x000021A1
.LvarGet_2B14:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2B24 @ =0x000021A2
    bl .LvarGet_35BA
    .align 2, 0
.LvarGet_2B24: .word 0x000021A2
.LvarGet_2B28:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2B34 @ =0x000021A2
    b .LvarGet_305A
    .align 2, 0
.LvarGet_2B34: .word 0x000021A2
.LvarGet_2B38:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2B48 @ =0x000021A2
    bl .LvarGet_3652
    .align 2, 0
.LvarGet_2B48: .word 0x000021A2
.LvarGet_2B4C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2B5C @ =0x000021A2
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_2B5C: .word 0x000021A2
.LvarGet_2B60:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2B70 @ =0x000021A2
    bl .LvarGet_352A
    .align 2, 0
.LvarGet_2B70: .word 0x000021A2
.LvarGet_2B74:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2B84 @ =0x000021A3
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2B84: .word 0x000021A3
.LvarGet_2B88:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2B98 @ =0x000021A3
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_2B98: .word 0x000021A3
.LvarGet_2B9C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2BAC @ =0x000021A3
    bl .LvarGet_356A
    .align 2, 0
.LvarGet_2BAC: .word 0x000021A3
.LvarGet_2BB0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2BC0 @ =0x000021A3
    bl .LvarGet_36D2
    .align 2, 0
.LvarGet_2BC0: .word 0x000021A3
.LvarGet_2BC4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2BE0 @ =0x000021A3
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #7
    ldr r1, .LvarGet_2BE4 @ =0x000021A4
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #1
    b .LvarGet_3170
    .align 2, 0
.LvarGet_2BE0: .word 0x000021A3
.LvarGet_2BE4: .word 0x000021A4
.LvarGet_2BE8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2BF8 @ =0x000021A4
    bl .LvarGet_3302
    .align 2, 0
.LvarGet_2BF8: .word 0x000021A4
.LvarGet_2BFC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2C0C @ =0x000021A4
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_2C0C: .word 0x000021A4
.LvarGet_2C10:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2C20 @ =0x000021A4
    bl .LvarGet_366A
    .align 2, 0
.LvarGet_2C20: .word 0x000021A4
.LvarGet_2C24:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2C30 @ =0x000021A4
    b .LvarGet_2D56
    .align 2, 0
.LvarGet_2C30: .word 0x000021A4
.LvarGet_2C34:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2C44 @ =0x000021A4
    bl .LvarGet_360A
    .align 2, 0
.LvarGet_2C44: .word 0x000021A4
.LvarGet_2C48:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2C58 @ =0x000021A5
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2C58: .word 0x000021A5
.LvarGet_2C5C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2C6C @ =0x000021A5
    bl .LvarGet_363A
    .align 2, 0
.LvarGet_2C6C: .word 0x000021A5
.LvarGet_2C70:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2C7C @ =0x000021A5
    b .LvarGet_2DA6
    .align 2, 0
.LvarGet_2C7C: .word 0x000021A5
.LvarGet_2C80:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2C8C @ =0x000021A5
    b .LvarGet_2D56
    .align 2, 0
.LvarGet_2C8C: .word 0x000021A5
.LvarGet_2C90:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2CA8 @ =0x000021A4
    adds r0, r0, r2
    ldr r0, [r0]
    lsls r0, r0, #0xe
    lsrs r0, r0, #0x1d
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_2CA8: .word 0x000021A4
.LvarGet_2CAC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2CBC @ =0x000021A6
    bl .LvarGet_363A
    .align 2, 0
.LvarGet_2CBC: .word 0x000021A6
.LvarGet_2CC0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2CD0 @ =0x000021A6
    bl .LvarGet_3652
    .align 2, 0
.LvarGet_2CD0: .word 0x000021A6
.LvarGet_2CD4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2CE4 @ =0x000021A6
    bl .LvarGet_366A
    .align 2, 0
.LvarGet_2CE4: .word 0x000021A6
.LvarGet_2CE8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2CF8 @ =0x000021A6
    bl .LvarGet_36BA
    .align 2, 0
.LvarGet_2CF8: .word 0x000021A6
.LvarGet_2CFC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2D0C @ =0x000021A6
    bl .LvarGet_36D2
    .align 2, 0
.LvarGet_2D0C: .word 0x000021A6
.LvarGet_2D10:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2D28 @ =0x000021A6
.LvarGet_2D1A:
    adds r0, r0, r2
    ldrh r0, [r0]
    lsls r0, r0, #0x17
    lsrs r0, r0, #0x1e
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_2D28: .word 0x000021A6
.LvarGet_2D2C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2D38 @ =0x000021A7
    b .LvarGet_305A
    .align 2, 0
.LvarGet_2D38: .word 0x000021A7
.LvarGet_2D3C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2D48 @ =0x000021A7
    b .LvarGet_2DA6
    .align 2, 0
.LvarGet_2D48: .word 0x000021A7
.LvarGet_2D4C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2D64 @ =0x000021A7
.LvarGet_2D56:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x19
    lsrs r0, r0, #0x1e
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_2D64: .word 0x000021A7
.LvarGet_2D68:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2D84 @ =0x000021A7
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #7
    ldr r1, .LvarGet_2D88 @ =0x000021A8
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #1
    b .LvarGet_3170
    .align 2, 0
.LvarGet_2D84: .word 0x000021A7
.LvarGet_2D88: .word 0x000021A8
.LvarGet_2D8C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2D98 @ =0x000021A8
    b .LvarGet_305A
    .align 2, 0
.LvarGet_2D98: .word 0x000021A8
.LvarGet_2D9C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2DB4 @ =0x000021A8
.LvarGet_2DA6:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1b
    lsrs r0, r0, #0x1e
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_2DB4: .word 0x000021A8
.LvarGet_2DB8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2DCC @ =0x000021A8
    adds r0, r0, r2
    ldrb r0, [r0]
    lsrs r0, r0, #5
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_2DCC: .word 0x000021A8
.LvarGet_2DD0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2DE0 @ =0x000021A9
    bl .LvarGet_3622
    .align 2, 0
.LvarGet_2DE0: .word 0x000021A9
.LvarGet_2DE4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2DF4 @ =0x000021A9
    bl .LvarGet_3552
    .align 2, 0
.LvarGet_2DF4: .word 0x000021A9
.LvarGet_2DF8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2E08 @ =0x000021A9
    bl .LvarGet_366A
    .align 2, 0
.LvarGet_2E08: .word 0x000021A9
.LvarGet_2E0C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2E1C @ =0x000021A9
    bl .LvarGet_36BA
    .align 2, 0
.LvarGet_2E1C: .word 0x000021A9
.LvarGet_2E20:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2E30 @ =0x000021A9
    bl .LvarGet_36D2
    .align 2, 0
.LvarGet_2E30: .word 0x000021A9
.LvarGet_2E34:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2E44 @ =0x000021A9
    bl .LvarGet_360A
    .align 2, 0
.LvarGet_2E44: .word 0x000021A9
.LvarGet_2E48:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2E58 @ =0x000021AA
    bl .LvarGet_35BA
    .align 2, 0
.LvarGet_2E58: .word 0x000021AA
.LvarGet_2E5C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2E68 @ =0x000021AA
    b .LvarGet_3302
    .align 2, 0
.LvarGet_2E68: .word 0x000021AA
.LvarGet_2E6C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2E7C @ =0x000021AA
    bl .LvarGet_363A
    .align 2, 0
.LvarGet_2E7C: .word 0x000021AA
.LvarGet_2E80:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2E90 @ =0x000021AA
    bl .LvarGet_3652
    .align 2, 0
.LvarGet_2E90: .word 0x000021AA
.LvarGet_2E94:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2EA4 @ =0x000021AA
    bl .LvarGet_366A
    .align 2, 0
.LvarGet_2EA4: .word 0x000021AA
.LvarGet_2EA8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2EB8 @ =0x000021AA
    bl .LvarGet_36BA
    .align 2, 0
.LvarGet_2EB8: .word 0x000021AA
.LvarGet_2EBC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2ECC @ =0x000021AA
    bl .LvarGet_36D2
    .align 2, 0
.LvarGet_2ECC: .word 0x000021AA
.LvarGet_2ED0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2EE0 @ =0x000021AA
    bl .LvarGet_360A
    .align 2, 0
.LvarGet_2EE0: .word 0x000021AA
.LvarGet_2EE4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2EF4 @ =0x000021AB
    bl .LvarGet_35BA
    .align 2, 0
.LvarGet_2EF4: .word 0x000021AB
.LvarGet_2EF8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2F04 @ =0x000021AB
    b .LvarGet_3302
    .align 2, 0
.LvarGet_2F04: .word 0x000021AB
.LvarGet_2F08:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2F18 @ =0x000021AB
    bl .LvarGet_363A
    .align 2, 0
.LvarGet_2F18: .word 0x000021AB
.LvarGet_2F1C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2F2C @ =0x000021AB
    bl .LvarGet_3652
    .align 2, 0
.LvarGet_2F2C: .word 0x000021AB
.LvarGet_2F30:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2F3C @ =0x000021B4
    b .LvarGet_2FFE
    .align 2, 0
.LvarGet_2F3C: .word 0x000021B4
.LvarGet_2F40:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2F4C @ =0x000021B4
    b .LvarGet_2FE2
    .align 2, 0
.LvarGet_2F4C: .word 0x000021B4
.LvarGet_2F50:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2F5C @ =0x000021B6
    b .LvarGet_2FFE
    .align 2, 0
.LvarGet_2F5C: .word 0x000021B6
.LvarGet_2F60:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2F74 @ =0x000021B7
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #6
    ldr r1, .LvarGet_2F78 @ =0x000021B8
    b .LvarGet_3024
    .align 2, 0
.LvarGet_2F74: .word 0x000021B7
.LvarGet_2F78: .word 0x000021B8
.LvarGet_2F7C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2F88 @ =0x000021B8
    b .LvarGet_2FFE
    .align 2, 0
.LvarGet_2F88: .word 0x000021B8
.LvarGet_2F8C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2F98 @ =0x000021B8
    b .LvarGet_2FE2
    .align 2, 0
.LvarGet_2F98: .word 0x000021B8
.LvarGet_2F9C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2FA8 @ =0x000021BA
    b .LvarGet_2FFE
    .align 2, 0
.LvarGet_2FA8: .word 0x000021BA
.LvarGet_2FAC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2FC0 @ =0x000021BB
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #6
    ldr r1, .LvarGet_2FC4 @ =0x000021BC
    b .LvarGet_3024
    .align 2, 0
.LvarGet_2FC0: .word 0x000021BB
.LvarGet_2FC4: .word 0x000021BC
.LvarGet_2FC8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2FD4 @ =0x000021BC
    b .LvarGet_2FFE
    .align 2, 0
.LvarGet_2FD4: .word 0x000021BC
.LvarGet_2FD8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_2FF0 @ =0x000021BC
.LvarGet_2FE2:
    adds r0, r0, r2
    ldr r0, [r0]
    lsls r0, r0, #0xa
    lsrs r0, r0, #0x18
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_2FF0: .word 0x000021BC
.LvarGet_2FF4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_300C @ =0x000021BE
.LvarGet_2FFE:
    adds r0, r0, r2
    ldrh r0, [r0]
    lsls r0, r0, #0x12
    lsrs r0, r0, #0x18
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_300C: .word 0x000021BE
.LvarGet_3010:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3034 @ =0x000021BF
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #6
    movs r1, #0x87
    lsls r1, r1, #6
.LvarGet_3024:
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #0x3f
    ands r0, r1
    lsls r0, r0, #2
    orrs r0, r2
    bl .LvarGetReturn
    .align 2, 0
.LvarGet_3034: .word 0x000021BF
.LvarGet_3038:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    movs r2, #0x87
    lsls r2, r2, #6
.LvarGet_3044:
    adds r0, r0, r2
    ldrh r0, [r0]
    lsls r0, r0, #0x17
    lsrs r0, r0, #0x1d
    bl .LvarGetReturn
.LvarGet_3050:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3064 @ =0x000021C1
.LvarGet_305A:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1d
    lsrs r0, r0, #0x1e
    b .LvarGetReturn
    .align 2, 0
.LvarGet_3064: .word 0x000021C1
.LvarGet_3068:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3074 @ =0x000021C1
    b .LvarGet_3652
    .align 2, 0
.LvarGet_3074: .word 0x000021C1
.LvarGet_3078:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3084 @ =0x000021C1
    b .LvarGet_366A
    .align 2, 0
.LvarGet_3084: .word 0x000021C1
.LvarGet_3088:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3094 @ =0x000021C1
    b .LvarGet_36BA
    .align 2, 0
.LvarGet_3094: .word 0x000021C1
.LvarGet_3098:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_30A4 @ =0x000021C1
    b .LvarGet_36D2
    .align 2, 0
.LvarGet_30A4: .word 0x000021C1
.LvarGet_30A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_30B4 @ =0x000021C1
    b .LvarGet_360A
    .align 2, 0
.LvarGet_30B4: .word 0x000021C1
.LvarGet_30B8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_30C4 @ =0x000021C2
    b .LvarGet_35BA
    .align 2, 0
.LvarGet_30C4: .word 0x000021C2
.LvarGet_30C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_30D4 @ =0x000021C2
    b .LvarGet_3302
    .align 2, 0
.LvarGet_30D4: .word 0x000021C2
.LvarGet_30D8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_30E4 @ =0x000021C2
    b .LvarGet_363A
    .align 2, 0
.LvarGet_30E4: .word 0x000021C2
.LvarGet_30E8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_30F4 @ =0x000021C2
    b .LvarGet_3652
    .align 2, 0
.LvarGet_30F4: .word 0x000021C2
.LvarGet_30F8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3104 @ =0x000021C2
    b .LvarGet_366A
    .align 2, 0
.LvarGet_3104: .word 0x000021C2
.LvarGet_3108:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3114 @ =0x000021C2
    b .LvarGet_36BA
    .align 2, 0
.LvarGet_3114: .word 0x000021C2
.LvarGet_3118:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3124 @ =0x000021C2
    b .LvarGet_36D2
    .align 2, 0
.LvarGet_3124: .word 0x000021C2
.LvarGet_3128:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_313C @ =0x000021C2
    adds r0, r0, r2
    ldrh r0, [r0]
    lsls r0, r0, #0x15
    lsrs r0, r0, #0x1c
    b .LvarGetReturn
    .align 2, 0
.LvarGet_313C: .word 0x000021C2
.LvarGet_3140:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3154 @ =0x000021C3
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x19
    lsrs r0, r0, #0x1c
    b .LvarGetReturn
    .align 2, 0
.LvarGet_3154: .word 0x000021C3
.LvarGet_3158:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3178 @ =0x000021C3
    adds r1, r0, r2
    ldrb r2, [r1]
    lsrs r2, r2, #7
    ldr r1, .LvarGet_317C @ =0x000021C4
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #7
.LvarGet_3170:
    ands r0, r1
    lsls r0, r0, #1
    orrs r0, r2
    b .LvarGetReturn
    .align 2, 0
.LvarGet_3178: .word 0x000021C3
.LvarGet_317C: .word 0x000021C4
.LvarGet_3180:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_318C @ =0x000021C4
    b .LvarGet_3652
    .align 2, 0
.LvarGet_318C: .word 0x000021C4
.LvarGet_3190:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_319C @ =0x000021C4
    b .LvarGet_366A
    .align 2, 0
.LvarGet_319C: .word 0x000021C4
.LvarGet_31A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_31AC @ =0x000021C4
    b .LvarGet_36BA
    .align 2, 0
.LvarGet_31AC: .word 0x000021C4
.LvarGet_31B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_31BC @ =0x000021C4
    b .LvarGet_36D2
    .align 2, 0
.LvarGet_31BC: .word 0x000021C4
.LvarGet_31C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_31CC @ =0x000021C4
    b .LvarGet_360A
    .align 2, 0
.LvarGet_31CC: .word 0x000021C4
.LvarGet_31D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_31DC @ =0x000021C5
    b .LvarGet_35BA
    .align 2, 0
.LvarGet_31DC: .word 0x000021C5
.LvarGet_31E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_31EC @ =0x000021C5
    b .LvarGet_3302
    .align 2, 0
.LvarGet_31EC: .word 0x000021C5
.LvarGet_31F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_31FC @ =0x000021C5
    b .LvarGet_363A
    .align 2, 0
.LvarGet_31FC: .word 0x000021C5
.LvarGet_3200:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_320C @ =0x000021C5
    b .LvarGet_3652
    .align 2, 0
.LvarGet_320C: .word 0x000021C5
.LvarGet_3210:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_321C @ =0x000021C5
    b .LvarGet_366A
    .align 2, 0
.LvarGet_321C: .word 0x000021C5
.LvarGet_3220:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_322C @ =0x000021C5
    b .LvarGet_36BA
    .align 2, 0
.LvarGet_322C: .word 0x000021C5
.LvarGet_3230:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_323C @ =0x000021C5
    b .LvarGet_36D2
    .align 2, 0
.LvarGet_323C: .word 0x000021C5
.LvarGet_3240:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_324C @ =0x000021C5
    b .LvarGet_360A
    .align 2, 0
.LvarGet_324C: .word 0x000021C5
.LvarGet_3250:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_325C @ =0x000021C6
    b .LvarGet_35BA
    .align 2, 0
.LvarGet_325C: .word 0x000021C6
.LvarGet_3260:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3274 @ =0x000021C6
    adds r0, r0, r2
    ldrh r0, [r0]
    lsls r0, r0, #0x17
    lsrs r0, r0, #0x18
    b .LvarGetReturn
    .align 2, 0
.LvarGet_3274: .word 0x000021C6
.LvarGet_3278:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3284 @ =0x000021C7
    b .LvarGet_3302
    .align 2, 0
.LvarGet_3284: .word 0x000021C7
.LvarGet_3288:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3294 @ =0x000021C7
    b .LvarGet_363A
    .align 2, 0
.LvarGet_3294: .word 0x000021C7
.LvarGet_3298:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_32A4 @ =0x000021C7
    b .LvarGet_3652
    .align 2, 0
.LvarGet_32A4: .word 0x000021C7
.LvarGet_32A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_32B4 @ =0x000021C7
    b .LvarGet_366A
    .align 2, 0
.LvarGet_32B4: .word 0x000021C7
.LvarGet_32B8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_32C4 @ =0x000021C7
    b .LvarGet_36BA
    .align 2, 0
.LvarGet_32C4: .word 0x000021C7
.LvarGet_32C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_32D4 @ =0x000021C7
    b .LvarGet_36D2
    .align 2, 0
.LvarGet_32D4: .word 0x000021C7
.LvarGet_32D8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_32E4 @ =0x000021C7
    b .LvarGet_360A
    .align 2, 0
.LvarGet_32E4: .word 0x000021C7
.LvarGet_32E8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_32F4 @ =0x000021C8
    b .LvarGet_35BA
    .align 2, 0
.LvarGet_32F4: .word 0x000021C8
.LvarGet_32F8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_330C @ =0x000021C8
.LvarGet_3302:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1f
    b .LvarGetReturn
    .align 2, 0
.LvarGet_330C: .word 0x000021C8
.LvarGet_3310:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_331C @ =0x000021AB
    b .LvarGet_356A
    .align 2, 0
.LvarGet_331C: .word 0x000021AB
.LvarGet_3320:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_332C @ =0x000021AB
    b .LvarGet_352A
    .align 2, 0
.LvarGet_332C: .word 0x000021AB
.LvarGet_3330:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_333C @ =0x000021AC
    b .LvarGet_3622
    .align 2, 0
.LvarGet_333C: .word 0x000021AC
.LvarGet_3340:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_334C @ =0x000021AC
    b .LvarGet_3552
    .align 2, 0
.LvarGet_334C: .word 0x000021AC
.LvarGet_3350:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_335C @ =0x000021AC
    b .LvarGet_356A
    .align 2, 0
.LvarGet_335C: .word 0x000021AC
.LvarGet_3360:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_336C @ =0x000021AC
    b .LvarGet_352A
    .align 2, 0
.LvarGet_336C: .word 0x000021AC
.LvarGet_3370:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_337C @ =0x000021AD
    b .LvarGet_3622
    .align 2, 0
.LvarGet_337C: .word 0x000021AD
.LvarGet_3380:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_338C @ =0x000021AD
    b .LvarGet_3552
    .align 2, 0
.LvarGet_338C: .word 0x000021AD
.LvarGet_3390:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_339C @ =0x000021AD
    b .LvarGet_356A
    .align 2, 0
.LvarGet_339C: .word 0x000021AD
.LvarGet_33A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_33AC @ =0x000021AD
    b .LvarGet_352A
    .align 2, 0
.LvarGet_33AC: .word 0x000021AD
.LvarGet_33B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_33BC @ =0x000021AE
    b .LvarGet_3622
    .align 2, 0
.LvarGet_33BC: .word 0x000021AE
.LvarGet_33C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_33CC @ =0x000021AE
    b .LvarGet_3552
    .align 2, 0
.LvarGet_33CC: .word 0x000021AE
.LvarGet_33D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_33DC @ =0x000021AE
    b .LvarGet_356A
    .align 2, 0
.LvarGet_33DC: .word 0x000021AE
.LvarGet_33E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_33EC @ =0x000021AE
    b .LvarGet_352A
    .align 2, 0
.LvarGet_33EC: .word 0x000021AE
.LvarGet_33F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_33FC @ =0x000021AF
    b .LvarGet_3622
    .align 2, 0
.LvarGet_33FC: .word 0x000021AF
.LvarGet_3400:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_340C @ =0x000021AF
    b .LvarGet_3552
    .align 2, 0
.LvarGet_340C: .word 0x000021AF
.LvarGet_3410:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_341C @ =0x000021AF
    b .LvarGet_356A
    .align 2, 0
.LvarGet_341C: .word 0x000021AF
.LvarGet_3420:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_342C @ =0x000021AF
    b .LvarGet_352A
    .align 2, 0
.LvarGet_342C: .word 0x000021AF
.LvarGet_3430:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_343C @ =0x000021B0
    b .LvarGet_3622
    .align 2, 0
.LvarGet_343C: .word 0x000021B0
.LvarGet_3440:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_344C @ =0x000021B0
    b .LvarGet_3552
    .align 2, 0
.LvarGet_344C: .word 0x000021B0
.LvarGet_3450:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_345C @ =0x000021B0
    b .LvarGet_356A
    .align 2, 0
.LvarGet_345C: .word 0x000021B0
.LvarGet_3460:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_346C @ =0x000021B0
    b .LvarGet_352A
    .align 2, 0
.LvarGet_346C: .word 0x000021B0
.LvarGet_3470:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_347C @ =0x000021B1
    b .LvarGet_3622
    .align 2, 0
.LvarGet_347C: .word 0x000021B1
.LvarGet_3480:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_348C @ =0x000021B1
    b .LvarGet_3552
    .align 2, 0
.LvarGet_348C: .word 0x000021B1
.LvarGet_3490:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_349C @ =0x000021B1
    b .LvarGet_356A
    .align 2, 0
.LvarGet_349C: .word 0x000021B1
.LvarGet_34A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_34AC @ =0x000021B1
    b .LvarGet_352A
    .align 2, 0
.LvarGet_34AC: .word 0x000021B1
.LvarGet_34B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_34BC @ =0x000021B2
    b .LvarGet_3622
    .align 2, 0
.LvarGet_34BC: .word 0x000021B2
.LvarGet_34C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_34CC @ =0x000021B2
    b .LvarGet_3552
    .align 2, 0
.LvarGet_34CC: .word 0x000021B2
.LvarGet_34D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_34DC @ =0x000021B2
    b .LvarGet_356A
    .align 2, 0
.LvarGet_34DC: .word 0x000021B2
.LvarGet_34E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_34EC @ =0x000021B2
    b .LvarGet_352A
    .align 2, 0
.LvarGet_34EC: .word 0x000021B2
.LvarGet_34F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_34FC @ =0x000021B3
    b .LvarGet_3622
    .align 2, 0
.LvarGet_34FC: .word 0x000021B3
.LvarGet_3500:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_350C @ =0x000021B3
    b .LvarGet_3552
    .align 2, 0
.LvarGet_350C: .word 0x000021B3
.LvarGet_3510:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_351C @ =0x000021B3
    b .LvarGet_356A
    .align 2, 0
.LvarGet_351C: .word 0x000021B3
.LvarGet_3520:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3534 @ =0x000021B3
.LvarGet_352A:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsrs r0, r0, #6
    b .LvarGetReturn
    .align 2, 0
.LvarGet_3534: .word 0x000021B3
.LvarGet_3538:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3544 @ =0x000021B4
    b .LvarGet_3622
    .align 2, 0
.LvarGet_3544: .word 0x000021B4
.LvarGet_3548:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_355C @ =0x000021B4
.LvarGet_3552:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1c
    lsrs r0, r0, #0x1e
    b .LvarGetReturn
    .align 2, 0
.LvarGet_355C: .word 0x000021B4
.LvarGet_3560:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3574 @ =0x000021B4
.LvarGet_356A:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1a
    lsrs r0, r0, #0x1e
    b .LvarGetReturn
    .align 2, 0
.LvarGet_3574: .word 0x000021B4
.LvarGet_3578:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3584 @ =0x000021C8
    b .LvarGet_363A
    .align 2, 0
.LvarGet_3584: .word 0x000021C8
.LvarGet_3588:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3594 @ =0x000021C8
    b .LvarGet_3652
    .align 2, 0
.LvarGet_3594: .word 0x000021C8
.LvarGet_3598:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_35AC @ =0x000021C8
    adds r0, r0, r2
    ldrb r0, [r0]
    lsrs r0, r0, #4
    b .LvarGetReturn
    .align 2, 0
.LvarGet_35AC: .word 0x000021C8
.LvarGet_35B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_35C4 @ =0x000021C9
.LvarGet_35BA:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1f
    lsrs r0, r0, #0x1f
    b .LvarGetReturn
    .align 2, 0
.LvarGet_35C4: .word 0x000021C9
.LvarGet_35C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_35DC @ =0x000021C9
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1b
    lsrs r0, r0, #0x1c
    b .LvarGetReturn
    .align 2, 0
.LvarGet_35DC: .word 0x000021C9
.LvarGet_35E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_35EC @ =0x000021C9
    b .LvarGet_36BA
    .align 2, 0
.LvarGet_35EC: .word 0x000021C9
.LvarGet_35F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_35FC @ =0x000021C9
    b .LvarGet_36D2
    .align 2, 0
.LvarGet_35FC: .word 0x000021C9
.LvarGet_3600:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3614 @ =0x000021C9
.LvarGet_360A:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsrs r0, r0, #7
    b .LvarGetReturn
    .align 2, 0
.LvarGet_3614: .word 0x000021C9
.LvarGet_3618:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_362C @ =0x000021CA
.LvarGet_3622:
    adds r0, r0, r2
    ldrb r0, [r0]
.LvarGet_3626:
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    b .LvarGetReturn
    .align 2, 0
.LvarGet_362C: .word 0x000021CA
.LvarGet_3630:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3644 @ =0x000021CA
.LvarGet_363A:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1d
    lsrs r0, r0, #0x1f
    b .LvarGetReturn
    .align 2, 0
.LvarGet_3644: .word 0x000021CA
.LvarGet_3648:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_365C @ =0x000021CA
.LvarGet_3652:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1c
    lsrs r0, r0, #0x1f
    b .LvarGetReturn
    .align 2, 0
.LvarGet_365C: .word 0x000021CA
.LvarGet_3660:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3674 @ =0x000021CA
.LvarGet_366A:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1b
    lsrs r0, r0, #0x1f
    b .LvarGetReturn
    .align 2, 0
.LvarGet_3674: .word 0x000021CA
.LvarGet_3678:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3684 @ =0x000021CA
    b .LvarGet_36BA
    .align 2, 0
.LvarGet_3684: .word 0x000021CA
.LvarGet_3688:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_3694 @ =0x000021CA
    b .LvarGet_36D2
    .align 2, 0
.LvarGet_3694: .word 0x000021CA
.LvarGet_3698:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_36AC @ =0x000021CB
    adds r0, r0, r2
    ldrb r0, [r0]
    lsrs r0, r0, #2
    b .LvarGetReturn
    .align 2, 0
.LvarGet_36AC: .word 0x000021CB
.LvarGet_36B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_36C4 @ =0x0000216E
.LvarGet_36BA:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1a
    lsrs r0, r0, #0x1f
    b .LvarGetReturn
    .align 2, 0
.LvarGet_36C4: .word 0x0000216E
.LvarGet_36C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r2, r1
    ldr r0, [r0]
    ldr r2, .LvarGet_36DC @ =0x0000216E
.LvarGet_36D2:
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x19
    lsrs r0, r0, #0x1f
    b .LvarGetReturn
    .align 2, 0
.LvarGet_36DC: .word 0x0000216E

    @ Return through VarGet's saved frame, including invalid variable IDs.
.LvarGetZero:
    movs r0, #0
.LvarGetReturn:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
