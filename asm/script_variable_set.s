    .include "asm/macro.inc"
    .syntax unified
    .thumb
    .text

    thumb_func_start VarSet__12ScriptEngineUii
VarSet__12ScriptEngineUii:
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #8
    adds r7, r0, #0
    mov r8, r1
    adds r6, r2, #0
    bl VarGet__12ScriptEngineUi
    mov sb, r0
    mov r1, r8
    subs r1, #0x1c
    ldr r0, .L0804902C
    cmp r1, r0
    bls .L08049020
    bl .L0804DA2E
.L08049020:
    lsls r0, r1, #2
    ldr r1, .L08049030 @ =.LvariableWriters
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0804902C: .word (.LvariableWritersEnd - .LvariableWriters) / 4 - 1
.L08049030: .word .LvariableWriters
.LvariableWriters: @ jump table
    .word .L08049A24 @ case 0
    .word .L0804DA2E @ case 1
    .word .L08049B32 @ case 2
    .word .L08049B4C @ case 3
    .word .L0804DA2E @ case 4
    .word .L0804DA2E @ case 5
    .word .L0804DA2E @ case 6
    .word .L0804DA2E @ case 7
    .word .L0804DA2E @ case 8
    .word .L0804DA2E @ case 9
    .word .L0804DA2E @ case 10
    .word .L0804DA2E @ case 11
    .word .L08049928 @ case 12
    .word .L08049956 @ case 13
    .word .L08049990 @ case 14
    .word .L080498FC @ case 15
    .word .L0804DA2E @ case 16
    .word .L0804DA2E @ case 17
    .word .L0804DA2E @ case 18
    .word .L080499E4 @ case 19
    .word .L0804DA2E @ case 20
    .word .L0804DA2E @ case 21
    .word .L0804DA2E @ case 22
    .word .L0804DA2E @ case 23
    .word .L0804DA2E @ case 24
    .word .L080499CA @ case 25
    .word .L0804DA2E @ case 26
    .word .L0804DA2E @ case 27
    .word .L0804DA2E @ case 28
    .word .L0804DA2E @ case 29
    .word .L0804DA2E @ case 30
    .word .L0804DA2E @ case 31
    .word .L0804DA2E @ case 32
    .word .L0804DA2E @ case 33
    .word .L0804DA2E @ case 34
    .word .L0804DA2E @ case 35
    .word .L0804DA2E @ case 36
    .word .L0804DA2E @ case 37
    .word .L0804DA2E @ case 38
    .word .L0804DA2E @ case 39
    .word .L0804DA2E @ case 40
    .word .L0804DA2E @ case 41
    .word .L08049D64 @ case 42
    .word .L08049D76 @ case 43
    .word .L0804A25C @ case 44
    .word .L08049D88 @ case 45
    .word .L08049D9A @ case 46
    .word .L08049DAC @ case 47
    .word .L08049DBE @ case 48
    .word .L0804A1C2 @ case 49
    .word .L08049DD0 @ case 50
    .word .L08049DE2 @ case 51
    .word .L08049DF4 @ case 52
    .word .L0804A280 @ case 53
    .word .L08049E06 @ case 54
    .word .L0804A2A0 @ case 55
    .word .L08049E18 @ case 56
    .word .L08049E2A @ case 57
    .word .L0804A1E4 @ case 58
    .word .L08049E3C @ case 59
    .word .L08049E4E @ case 60
    .word .L0804A2C0 @ case 61
    .word .L08049E60 @ case 62
    .word .L0804A2E4 @ case 63
    .word .L08049E72 @ case 64
    .word .L0804A304 @ case 65
    .word .L08049E84 @ case 66
    .word .L08049E96 @ case 67
    .word .L0804A200 @ case 68
    .word .L08049EA8 @ case 69
    .word .L08049EBA @ case 70
    .word .L0804A324 @ case 71
    .word .L08049ECC @ case 72
    .word .L08049EDE @ case 73
    .word .L08049EF0 @ case 74
    .word .L08049F02 @ case 75
    .word .L0804A220 @ case 76
    .word .L08049F14 @ case 77
    .word .L08049F24 @ case 78
    .word .L08049F34 @ case 79
    .word .L0804A344 @ case 80
    .word .L08049F44 @ case 81
    .word .L08049F54 @ case 82
    .word .L08049F64 @ case 83
    .word .L0804A23C @ case 84
    .word .L08049FA0 @ case 85
    .word .L08049FB0 @ case 86
    .word .L08049FC2 @ case 87
    .word .L08049FD4 @ case 88
    .word .L08049FE6 @ case 89
    .word .L08049FF8 @ case 90
    .word .L0804A00A @ case 91
    .word .L0804A368 @ case 92
    .word .L0804A404 @ case 93
    .word .L0804A01C @ case 94
    .word .L0804A02C @ case 95
    .word .L0804A03E @ case 96
    .word .L0804A050 @ case 97
    .word .L0804A062 @ case 98
    .word .L0804A074 @ case 99
    .word .L0804A388 @ case 100
    .word .L0804A424 @ case 101
    .word .L0804A086 @ case 102
    .word .L0804A096 @ case 103
    .word .L0804A0A8 @ case 104
    .word .L0804A0BA @ case 105
    .word .L0804A0CC @ case 106
    .word .L0804A0DE @ case 107
    .word .L0804A3A8 @ case 108
    .word .L0804A438 @ case 109
    .word .L0804A0F0 @ case 110
    .word .L0804A100 @ case 111
    .word .L0804A112 @ case 112
    .word .L0804A124 @ case 113
    .word .L0804A136 @ case 114
    .word .L0804A148 @ case 115
    .word .L0804A3C4 @ case 116
    .word .L0804A45C @ case 117
    .word .L0804A15A @ case 118
    .word .L0804A168 @ case 119
    .word .L0804A178 @ case 120
    .word .L0804A188 @ case 121
    .word .L0804A198 @ case 122
    .word .L0804A1A8 @ case 123
    .word .L0804A3E4 @ case 124
    .word .L0804A47C @ case 125
    .word .L0804A49C @ case 126
    .word .L0804A4BC @ case 127
    .word .L0804A4E0 @ case 128
    .word .L0804A500 @ case 129
    .word .L0804A520 @ case 130
    .word .L0804A540 @ case 131
    .word .L0804A564 @ case 132
    .word .L0804A584 @ case 133
    .word .L0804A5A4 @ case 134
    .word .L0804A5C4 @ case 135
    .word .L0804A5FC @ case 136
    .word .L0804A61C @ case 137
    .word .L0804A63C @ case 138
    .word .L0804A65C @ case 139
    .word .L0804A680 @ case 140
    .word .L0804A6A0 @ case 141
    .word .L0804A6C0 @ case 142
    .word .L0804A6E0 @ case 143
    .word .L0804A704 @ case 144
    .word .L0804A724 @ case 145
    .word .L0804A744 @ case 146
    .word .L0804A764 @ case 147
    .word .L0804A788 @ case 148
    .word .L0804A7A8 @ case 149
    .word .L0804A7C8 @ case 150
    .word .L0804A7E8 @ case 151
    .word .L0804A820 @ case 152
    .word .L0804A840 @ case 153
    .word .L0804A860 @ case 154
    .word .L0804A880 @ case 155
    .word .L0804A8A4 @ case 156
    .word .L0804A8C4 @ case 157
    .word .L0804A8E4 @ case 158
    .word .L0804A904 @ case 159
    .word .L0804A928 @ case 160
    .word .L0804A948 @ case 161
    .word .L0804A968 @ case 162
    .word .L0804A988 @ case 163
    .word .L0804A9AC @ case 164
    .word .L0804A9CC @ case 165
    .word .L0804A9EC @ case 166
    .word .L0804AA0C @ case 167
    .word .L0804AA44 @ case 168
    .word .L0804AA64 @ case 169
    .word .L0804AA84 @ case 170
    .word .L0804AAA4 @ case 171
    .word .L0804AAEC @ case 172
    .word .L0804AB0C @ case 173
    .word .L0804AB2C @ case 174
    .word .L0804AB4C @ case 175
    .word .L0804AB70 @ case 176
    .word .L0804AB90 @ case 177
    .word .L0804ABB0 @ case 178
    .word .L0804ABD0 @ case 179
    .word .L0804ABF4 @ case 180
    .word .L0804AC14 @ case 181
    .word .L0804AC34 @ case 182
    .word .L0804AC54 @ case 183
    .word .L0804AC8C @ case 184
    .word .L0804ACAC @ case 185
    .word .L0804ACCC @ case 186
    .word .L0804ACEC @ case 187
    .word .L0804AD10 @ case 188
    .word .L0804AD30 @ case 189
    .word .L0804AD50 @ case 190
    .word .L0804AD70 @ case 191
    .word .L0804AD94 @ case 192
    .word .L0804ADB4 @ case 193
    .word .L0804ADD4 @ case 194
    .word .L0804AE04 @ case 195
    .word .L0804AE24 @ case 196
    .word .L0804AE44 @ case 197
    .word .L0804AE68 @ case 198
    .word .L0804AE88 @ case 199
    .word .L0804AEA8 @ case 200
    .word .L0804AEC8 @ case 201
    .word .L0804AEE4 @ case 202
    .word .L0804AF08 @ case 203
    .word .L0804AF28 @ case 204
    .word .L0804AF48 @ case 205
    .word .L0804AF64 @ case 206
    .word .L0804AF88 @ case 207
    .word .L0804AFA8 @ case 208
    .word .L0804AFC8 @ case 209
    .word .L0804AFE4 @ case 210
    .word .L0804B008 @ case 211
    .word .L0804B028 @ case 212
    .word .L0804B048 @ case 213
    .word .L0804B064 @ case 214
    .word .L0804B088 @ case 215
    .word .L0804B0A8 @ case 216
    .word .L0804B0C8 @ case 217
    .word .L0804B0E8 @ case 218
    .word .L0804B0FC @ case 219
    .word .L0804B118 @ case 220
    .word .L0804B13C @ case 221
    .word .L0804B15C @ case 222
    .word .L0804B17C @ case 223
    .word .L0804B19C @ case 224
    .word .L0804B1C0 @ case 225
    .word .L0804B1E0 @ case 226
    .word .L0804B200 @ case 227
    .word .L0804B220 @ case 228
    .word .L0804B23C @ case 229
    .word .L0804B260 @ case 230
    .word .L0804B280 @ case 231
    .word .L0804B2A0 @ case 232
    .word .L0804B2BC @ case 233
    .word .L0804B2E0 @ case 234
    .word .L0804B300 @ case 235
    .word .L0804B320 @ case 236
    .word .L0804B344 @ case 237
    .word .L0804B364 @ case 238
    .word .L0804B384 @ case 239
    .word .L0804B3A4 @ case 240
    .word .L0804B3C0 @ case 241
    .word .L0804B3E4 @ case 242
    .word .L0804B404 @ case 243
    .word .L0804B43C @ case 244
    .word .L0804B45C @ case 245
    .word .L0804B47C @ case 246
    .word .L0804B49C @ case 247: variable 275 (id - 0x1C)
    .word .L0804B4B8 @ case 248
    .word .L0804B4DC @ case 249
    .word .L0804B4FC @ case 250
    .word .L0804B51C @ case 251
    .word .L0804B538 @ case 252
    .word .L0804B55C @ case 253
    .word .L0804B57C @ case 254
    .word .L0804B59C @ case 255
    .word .L0804B5B8 @ case 256
    .word .L0804B5DC @ case 257
    .word .L0804B5FC @ case 258
    .word .L0804B61C @ case 259
    .word .L0804B638 @ case 260
    .word .L0804B658 @ case 261
    .word .L0804B676 @ case 262
    .word .L0804B694 @ case 263
    .word .L0804B6AC @ case 264
    .word .L0804B6D0 @ case 265
    .word .L0804B6F0 @ case 266
    .word .L0804B710 @ case 267
    .word .L0804B72C @ case 268
    .word .L0804B750 @ case 269
    .word .L0804B770 @ case 270
    .word .L0804B790 @ case 271
    .word .L0804B7B0 @ case 272
    .word .L0804B7D4 @ case 273
    .word .L0804B7F4 @ case 274
    .word .L0804B814 @ case 275
    .word .L0804B834 @ case 276
    .word .L0804B86C @ case 277
    .word .L0804B88C @ case 278
    .word .L0804B8AC @ case 279
    .word .L0804B8CC @ case 280
    .word .L0804B8E8 @ case 281
    .word .L0804B90C @ case 282
    .word .L0804B92C @ case 283
    .word .L0804B94C @ case 284
    .word .L0804B968 @ case 285
    .word .L0804B98C @ case 286
    .word .L0804B9AC @ case 287
    .word .L0804B9CC @ case 288
    .word .L0804B9F0 @ case 289
    .word .L0804BA10 @ case 290
    .word .L0804BA30 @ case 291
    .word .L0804BA50 @ case 292
    .word .L0804BA88 @ case 293
    .word .L0804BAA8 @ case 294
    .word .L0804BAC8 @ case 295
    .word .L0804BAE8 @ case 296
    .word .L0804BB0C @ case 297
    .word .L0804BB2C @ case 298
    .word .L0804BB4C @ case 299
    .word .L0804BB70 @ case 300
    .word .L0804BB90 @ case 301
    .word .L0804BBB0 @ case 302
    .word .L0804BBCC @ case 303
    .word .L0804BBF0 @ case 304
    .word .L0804BC10 @ case 305
    .word .L0804BC48 @ case 306
    .word .L0804BC68 @ case 307
    .word .L0804BC88 @ case 308
    .word .L0804BCA8 @ case 309
    .word .L0804BCCC @ case 310
    .word .L0804BCEC @ case 311
    .word .L0804BD0C @ case 312
    .word .L0804BD30 @ case 313
    .word .L0804BD50 @ case 314
    .word .L0804BD70 @ case 315
    .word .L0804BD90 @ case 316
    .word .L0804BDAC @ case 317
    .word .L0804BDD0 @ case 318
    .word .L0804BDF0 @ case 319
    .word .L0804BE10 @ case 320
    .word .L0804BE2C @ case 321
    .word .L0804BE50 @ case 322
    .word .L0804BE70 @ case 323
    .word .L0804BE90 @ case 324
    .word .L0804BEAC @ case 325
    .word .L0804BED0 @ case 326
    .word .L0804BEF0 @ case 327
    .word .L0804BF10 @ case 328
    .word .L0804BF2C @ case 329
    .word .L0804BF50 @ case 330
    .word .L0804BF70 @ case 331
    .word .L0804BF90 @ case 332
    .word .L0804BFAC @ case 333
    .word .L0804BFD0 @ case 334
    .word .L0804BFF0 @ case 335
    .word .L0804C010 @ case 336
    .word .L0804C02C @ case 337
    .word .L0804C050 @ case 338
    .word .L0804C070 @ case 339
    .word .L0804C090 @ case 340
    .word .L0804C0AC @ case 341
    .word .L08049F74 @ case 342
    .word .L08049F88 @ case 343
    .word .L0804C0D0 @ case 344
    .word .L0804C0EC @ case 345
    .word .L0804C110 @ case 346
    .word .L0804C130 @ case 347
    .word .L0804C150 @ case 348
    .word .L0804AAC8 @ case 349
    .word .L0804C16C @ case 350
    .word .L0804C18C @ case 351
    .word .L0804C1AC @ case 352
    .word .L0804C1C8 @ case 353
    .word .L0804C1EC @ case 354
    .word .L0804C20C @ case 355
    .word .L0804C22C @ case 356
    .word .L0804C248 @ case 357
    .word .L0804C26C @ case 358
    .word .L0804C28C @ case 359
    .word .L0804C2AC @ case 360
    .word .L0804C2CC @ case 361
    .word .L0804C2EC @ case 362
    .word .L0804C300 @ case 363
    .word .L08049AAA @ case 364
    .word .L0804C324 @ case 365
    .word .L08049B94 @ case 366
    .word .L0804C344 @ case 367
    .word .L0804C364 @ case 368
    .word .L0804C388 @ case 369
    .word .L0804C3A8 @ case 370
    .word .L0804C3C8 @ case 371
    .word .L0804C3DC @ case 372
    .word .L0804DA2E @ case 373
    .word .L0804C414 @ case 374
    .word .L08049A54 @ case 375
    .word .L0804C434 @ case 376
    .word .L08049BE0 @ case 377
    .word .L0804C454 @ case 378
    .word .L0804C478 @ case 379
    .word .L0804C498 @ case 380
    .word .L08049C24 @ case 381
    .word .L0804C4B8 @ case 382
    .word .L0804C4D4 @ case 383
    .word .L0804C4F8 @ case 384
    .word .L08049C70 @ case 385
    .word .L0804C518 @ case 386
    .word .L0804C538 @ case 387
    .word .L0804C55C @ case 388
    .word .L0804C57C @ case 389
    .word .L0804C59C @ case 390
    .word .L0804C5BC @ case 391
    .word .L0804C5D8 @ case 392
    .word .L0804C5FC @ case 393
    .word .L0804C61C @ case 394
    .word .L0804C63C @ case 395: variable 423 (id - 0x1C)
    .word .L0804C65C @ case 396
    .word .L0804C67C @ case 397
    .word .L0804C6A0 @ case 398
    .word .L08049AD4 @ case 399
    .word .L0804C6C4 @ case 400
    .word .L08049CBC @ case 401
    .word .L0804C6E4 @ case 402
    .word .L0804C700 @ case 403
    .word .L0804C724 @ case 404
    .word .L08049D08 @ case 405
    .word .L0804C744 @ case 406
    .word .L0804C764 @ case 407
    .word .L0804C780 @ case 408
    .word .L0804C7A4 @ case 409
    .word .L0804C7C4 @ case 410
    .word .L0804C7E4 @ case 411
    .word .L0804C7F8 @ case 412
    .word .L0804C830 @ case 413
    .word .L0804C850 @ case 414
    .word .L0804C870 @ case 415
    .word .L0804C890 @ case 416
    .word .L0804C8B0 @ case 417
    .word .L0804C8CC @ case 418
    .word .L0804C8F0 @ case 419
    .word .L0804C910 @ case 420
    .word .L0804C930 @ case 421
    .word .L0804C950 @ case 422
    .word .L0804C970 @ case 423
    .word .L0804C990 @ case 424
    .word .L0804C9B0 @ case 425
    .word .L0804C9D0 @ case 426
    .word .L0804C9F0 @ case 427
    .word .L0804CA04 @ case 428
    .word .L0804CA28 @ case 429
    .word .L0804CA48 @ case 430
    .word .L0804CA68 @ case 431
    .word .L0804CA88 @ case 432
    .word .L0804CAC0 @ case 433
    .word .L0804CAE0 @ case 434
    .word .L0804CB00 @ case 435
    .word .L0804CB1C @ case 436
    .word .L0804CB40 @ case 437
    .word .L0804CB60 @ case 438
    .word .L0804CB80 @ case 439
    .word .L0804CBA0 @ case 440
    .word .L0804CBB4 @ case 441
    .word .L0804CBD0 @ case 442
    .word .L0804CBF4 @ case 443
    .word .L0804CC14 @ case 444
    .word .L0804CC34 @ case 445
    .word .L0804CC54 @ case 446
    .word .L0804CC74 @ case 447
    .word .L0804CC94 @ case 448
    .word .L0804CCA8 @ case 449
    .word .L0804CCC4 @ case 450
    .word .L0804CCE8 @ case 451
    .word .L0804CD08 @ case 452
    .word .L0804CD28 @ case 453
    .word .L0804CD48 @ case 454
    .word .L0804CD68 @ case 455
    .word .L0804CD78 @ case 456
    .word .L0804CD98 @ case 457
    .word .L0804CDD0 @ case 458
    .word .L0804CDF0 @ case 459
    .word .L0804CE00 @ case 460
    .word .L0804CE20 @ case 461
    .word .L0804CE58 @ case 462
    .word .L0804CE78 @ case 463
    .word .L0804CEA0 @ case 464
    .word .L0804CEC0 @ case 465
    .word .L0804CEF4 @ case 466
    .word .L0804CF14 @ case 467
    .word .L0804CF34 @ case 468
    .word .L0804CF54 @ case 469
    .word .L0804CF74 @ case 470
    .word .L0804CF94 @ case 471
    .word .L0804CFA8 @ case 472
    .word .L0804CFC4 @ case 473
    .word .L0804CFE8 @ case 474
    .word .L0804D008 @ case 475
    .word .L0804D028 @ case 476
    .word .L0804D048 @ case 477
    .word .L0804D068 @ case 478
    .word .L0804D088 @ case 479
    .word .L0804D09C @ case 480
    .word .L0804D0BC @ case 481
    .word .L0804D0DC @ case 482
    .word .L0804D118 @ case 483
    .word .L0804D138 @ case 484
    .word .L0804D158 @ case 485
    .word .L0804D178 @ case 486
    .word .L0804D18C @ case 487
    .word .L0804D1A8 @ case 488
    .word .L0804D1CC @ case 489
    .word .L0804D1EC @ case 490
    .word .L0804D20C @ case 491
    .word .L0804D22C @ case 492
    .word .L0804D24C @ case 493
    .word .L0804D26C @ case 494
    .word .L0804D280 @ case 495
    .word .L0804D29C @ case 496
    .word .L0804D2C0 @ case 497
    .word .L0804D2E8 @ case 498
    .word .L0804D308 @ case 499
    .word .L0804D328 @ case 500
    .word .L0804D348 @ case 501
    .word .L0804D368 @ case 502
    .word .L0804D388 @ case 503
    .word .L0804D398 @ case 504
    .word .L0804D3B0 @ case 505
    .word .L0804D3D0 @ case 506
    .word .L0804D3F0 @ case 507
    .word .L0804D410 @ case 508
    .word .L0804D428 @ case 509
    .word .L0804D448 @ case 510
    .word .L0804D468 @ case 511
    .word .L0804D488 @ case 512
    .word .L0804D4A0 @ case 513
    .word .L0804D4C0 @ case 514
    .word .L0804D4E0 @ case 515
    .word .L0804D500 @ case 516
    .word .L0804D518 @ case 517
    .word .L0804D538 @ case 518
    .word .L0804D558 @ case 519
    .word .L0804D578 @ case 520
    .word .L0804D590 @ case 521
    .word .L0804D5B0 @ case 522
    .word .L0804D5D0 @ case 523
    .word .L0804D5F0 @ case 524
    .word .L0804D608 @ case 525
    .word .L0804D628 @ case 526
    .word .L0804D648 @ case 527
    .word .L0804D668 @ case 528
    .word .L0804D680 @ case 529
    .word .L0804D6A0 @ case 530
    .word .L0804D6C0 @ case 531
    .word .L0804D6E0 @ case 532
    .word .L0804D6F8 @ case 533
    .word .L0804D718 @ case 534
    .word .L0804D738 @ case 535
    .word .L0804D758 @ case 536
    .word .L0804D770 @ case 537
    .word .L0804D790 @ case 538
    .word .L0804D7B0 @ case 539
    .word .L0804D7D0 @ case 540
    .word .L0804D7E8 @ case 541
    .word .L0804D808 @ case 542
    .word .L0804D828 @ case 543
    .word .L0804D848 @ case 544
    .word .L0804D868 @ case 545
    .word .L0804D888 @ case 546
    .word .L0804D8A0 @ case 547
    .word .L0804D8C0 @ case 548
    .word .L0804D8E0 @ case 549
    .word .L0804D900 @ case 550
    .word .L0804D910 @ case 551
    .word .L0804D928 @ case 552
    .word .L0804D948 @ case 553
    .word .L0804D968 @ case 554
    .word .L0804D988 @ case 555
    .word .L0804D9A8 @ case 556
    .word .L0804D9C8 @ case 557
    .word .L0804D9D8 @ case 558
    .word .L0804D9F0 @ case 559
    .word .L0804DA10 @ case 560
    .word .L08049B78 @ case 561
.LvariableWritersEnd:
.L080498FC:
    cmp r6, #0
    beq .L08049904
    bl .L0804DA2E
.L08049904:
    movs r0, #0xd4
    lsls r0, r0, #2
    adds r4, r7, r0
    ldr r0, [r4]
    adds r0, #0x14
    bl GetUnkFlag11__C4Farm
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L0804991C
    bl .L0804DA2E
.L0804991C:
    ldr r0, [r4]
    adds r0, #0x14
    bl method_08009C60__4Farm
    bl .L0804DA2E
.L08049928:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r4, r7, r1
    ldr r0, [r4]
    adds r0, #0x14
    bl GetUnk10__C4Farm
    subs r1, r6, r0
    cmp r1, #0
    blt .L08049948
    ldr r0, [r4]
    adds r0, #0x14
    bl method_08009B68__4FarmUi
    bl .L0804DA2E
.L08049948:
    ldr r0, [r4]
    adds r0, #0x14
    rsbs r1, r1, #0
    bl method_08009BAC__4FarmUi
    bl .L0804DA2E
.L08049956:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r4, r7, r2
    ldr r0, [r4]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetStoredBushelCount__C4Barn
    subs r1, r6, r0
    cmp r1, #0
    blt .L0804997E
    ldr r0, [r4]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r0, r0, r2
    bl AddStoredBushels__4BarnUi
    bl .L0804DA2E
.L0804997E:
    ldr r0, [r4]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r0, r0, r2
    rsbs r1, r1, #0
    bl SubtractStoredBushels__4BarnUi
    bl .L0804DA2E
.L08049990:
    movs r0, #0xd4
    lsls r0, r0, #2
    adds r4, r7, r0
    ldr r0, [r4]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetStoredBushelCount__C4Coop
    subs r1, r6, r0
    cmp r1, #0
    blt .L080499B8
    ldr r0, [r4]
    movs r2, #0x82
    lsls r2, r2, #3
    adds r0, r0, r2
    bl AddStoredBushels__4CoopUi
    bl .L0804DA2E
.L080499B8:
    ldr r0, [r4]
    movs r2, #0x82
    lsls r2, r2, #3
    adds r0, r0, r2
    rsbs r1, r1, #0
    bl SubtractStoredBushels__4CoopUi
    bl .L0804DA2E
.L080499CA:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    rsbs r0, r6, #0
    orrs r0, r6
    lsrs r0, r0, #0x1f
    ldr r2, .L080499E0 @ =0x00002148
    adds r1, r1, r2
    bl .L0804DA2C
    .align 2, 0
.L080499E0: .word 0x00002148
.L080499E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    ldr r2, .L08049A20 @ =0x00001CD4
    adds r0, r0, r2
    bl GetChild__13NpcCollection
    adds r4, r0, #0
    cmp r4, #0
    bne .L080499FE
    bl .L0804DA2E
.L080499FE:
    cmp r6, #0
    bne .L08049A06
    bl .L0804DA2E
.L08049A06:
    bl CanWalk__C5Child
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L08049A14
    bl .L0804DA2E
.L08049A14:
    adds r0, r4, #0
    bl SetCanWalk__5Child
    bl .L0804DA2E
    .align 2, 0
.L08049A20: .word 0x00001CD4
.L08049A24:
    movs r0, #0xd4
    lsls r0, r0, #2
    adds r4, r7, r0
    ldr r0, [r4]
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r0, r5
    bl HasVase__C9FarmHouse
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L08049A40
    bl .L0804DA2E
.L08049A40:
    cmp r6, #0
    bne .L08049A48
    bl .L0804DA2E
.L08049A48:
    ldr r0, [r4]
    adds r0, r0, r5
    bl AddVase__9FarmHouse
    bl .L0804DA2E
.L08049A54:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r2, [r0]
    ldr r0, .L08049A8C @ =0x0000219C
    adds r2, r2, r0
    movs r0, #1
    adds r1, r6, #0
    ands r1, r0
    lsls r1, r1, #4
    ldrb r3, [r2]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r1
    strb r0, [r2]
    cmp r6, #0
    beq .L08049A90
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .L08049A88
    bl .L0804DA2E
.L08049A88:
    movs r1, #4
    b .L08049B0A
    .align 2, 0
.L08049A8C: .word 0x0000219C
.L08049A90:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r7, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .L08049AA0
    bl .L0804DA2E
.L08049AA0:
    movs r1, #4
    bl ClearContestAnimal__9GameScene14MaryAnimalKind
    bl .L0804DA2E
.L08049AAA:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r2, [r0]
    ldr r0, .L08049AD0 @ =0x0000219A
    adds r2, r2, r0
    movs r0, #1
    adds r1, r6, #0
    ands r1, r0
    lsls r1, r1, #1
    ldrb r3, [r2]
    movs r0, #3
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r1
    strb r0, [r2]
    cmp r6, #0
    bne .L08049AF8
    b .L08049B18
    .align 2, 0
.L08049AD0: .word 0x0000219A
.L08049AD4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r2, [r0]
    ldr r0, .L08049B14 @ =0x000021A1
    adds r2, r2, r0
    movs r0, #1
    adds r1, r6, #0
    ands r1, r0
    lsls r1, r1, #2
    ldrb r3, [r2]
    movs r0, #5
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r1
    strb r0, [r2]
    cmp r6, #0
    beq .L08049B18
.L08049AF8:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .L08049B08
    bl .L0804DA2E
.L08049B08:
    movs r1, #0
.L08049B0A:
    movs r2, #0
    bl SetContestAnimal__9GameScene14MaryAnimalKind19MaryAnimalSlotIndex
    bl .L0804DA2E
    .align 2, 0
.L08049B14: .word 0x000021A1
.L08049B18:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r7, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .L08049B28
    bl .L0804DA2E
.L08049B28:
    movs r1, #0
    bl ClearContestAnimal__9GameScene14MaryAnimalKind
    bl .L0804DA2E
.L08049B32:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl AddStocking__9FarmHouse
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r7, r1
    b .L08049B66
.L08049B4C:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r7, r2
    ldr r0, [r0]
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r1, r6, #0
    bl SetStockingArticleId__9FarmHouseUi
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r7, r2
.L08049B66:
    ldr r0, [r0]
    cmp r0, #0
    bne .L08049B70
    bl .L0804DA2E
.L08049B70:
    bl func_08016C10__9GameScene
    bl .L0804DA2E
.L08049B78:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    ldr r2, .L08049B90 @ =0x00001CD4
    adds r0, r0, r2
    adds r1, r6, #0
    bl func_080A03A4
    bl .L0804DA2E
    .align 2, 0
.L08049B90: .word 0x00001CD4
.L08049B94:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r2, [r0]
    ldr r0, .L08049BDC @ =0x0000219A
    adds r2, r2, r0
    movs r0, #1
    adds r1, r6, #0
    ands r1, r0
    lsls r1, r1, #4
    ldrb r3, [r2]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r1
    strb r0, [r2]
    cmp r6, #0
    bne .L08049BBC
    bl .L0804DA2E
.L08049BBC:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .L08049BCC
    bl .L0804DA2E
.L08049BCC:
    movs r1, #0
    bl GetContestAnimalIndex__9GameScene14MaryAnimalKind
    adds r2, r0, #0
    adds r0, r7, #0
    movs r1, #0
    b .L08049D4C
    .align 2, 0
.L08049BDC: .word 0x0000219A
.L08049BE0:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r7, r2
    ldr r1, [r0]
    ldr r0, .L08049C20 @ =0x0000219C
    adds r1, r1, r0
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    ands r0, r2
    orrs r0, r3
    strb r0, [r1]
    cmp r6, #0
    bne .L08049C00
    bl .L0804DA2E
.L08049C00:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .L08049C10
    bl .L0804DA2E
.L08049C10:
    movs r1, #4
    bl GetContestAnimalIndex__9GameScene14MaryAnimalKind
    adds r2, r0, #0
    adds r0, r7, #0
    movs r1, #4
    b .L08049D4C
    .align 2, 0
.L08049C20: .word 0x0000219C
.L08049C24:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r7, r2
    ldr r2, [r0]
    ldr r0, .L08049C6C @ =0x0000219D
    adds r2, r2, r0
    movs r0, #1
    adds r1, r6, #0
    ands r1, r0
    lsls r1, r1, #5
    ldrb r3, [r2]
    movs r0, #0x21
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r1
    strb r0, [r2]
    cmp r6, #0
    bne .L08049C4C
    bl .L0804DA2E
.L08049C4C:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .L08049C5C
    bl .L0804DA2E
.L08049C5C:
    movs r1, #3
    bl GetContestAnimalIndex__9GameScene14MaryAnimalKind
    adds r2, r0, #0
    adds r0, r7, #0
    movs r1, #3
    b .L08049D4C
    .align 2, 0
.L08049C6C: .word 0x0000219D
.L08049C70:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r7, r2
    ldr r2, [r0]
    ldr r0, .L08049CB8 @ =0x0000219E
    adds r2, r2, r0
    movs r0, #1
    adds r1, r6, #0
    ands r1, r0
    lsls r1, r1, #3
    ldrb r3, [r2]
    movs r0, #9
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r1
    strb r0, [r2]
    cmp r6, #0
    bne .L08049C98
    bl .L0804DA2E
.L08049C98:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .L08049CA8
    bl .L0804DA2E
.L08049CA8:
    movs r1, #1
    bl GetContestAnimalIndex__9GameScene14MaryAnimalKind
    adds r2, r0, #0
    adds r0, r7, #0
    movs r1, #1
    b .L08049D4C
    .align 2, 0
.L08049CB8: .word 0x0000219E
.L08049CBC:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r7, r2
    ldr r2, [r0]
    ldr r0, .L08049D04 @ =0x000021A1
    adds r2, r2, r0
    movs r0, #1
    adds r1, r6, #0
    ands r1, r0
    lsls r1, r1, #5
    ldrb r3, [r2]
    movs r0, #0x21
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r1
    strb r0, [r2]
    cmp r6, #0
    bne .L08049CE4
    bl .L0804DA2E
.L08049CE4:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .L08049CF4
    bl .L0804DA2E
.L08049CF4:
    movs r1, #0
    bl GetContestAnimalIndex__9GameScene14MaryAnimalKind
    adds r2, r0, #0
    adds r0, r7, #0
    movs r1, #0
    b .L08049D4C
    .align 2, 0
.L08049D04: .word 0x000021A1
.L08049D08:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r7, r2
    ldr r2, [r0]
    ldr r0, .L08049D60 @ =0x000021A2
    adds r2, r2, r0
    movs r0, #1
    adds r1, r6, #0
    ands r1, r0
    lsls r1, r1, #3
    ldrb r3, [r2]
    movs r0, #9
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r1
    strb r0, [r2]
    cmp r6, #0
    bne .L08049D30
    bl .L0804DA2E
.L08049D30:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .L08049D40
    bl .L0804DA2E
.L08049D40:
    movs r1, #2
    bl GetContestAnimalIndex__9GameScene14MaryAnimalKind
    adds r2, r0, #0
    adds r0, r7, #0
    movs r1, #2
.L08049D4C:
    bl func_0804E3D8
    cmp r0, #0
    bne .L08049D58
    bl .L0804DA2E
.L08049D58:
    bl SetFestivalWinner__6Animal
    bl .L0804DA2E
    .align 2, 0
.L08049D60: .word 0x000021A2
.L08049D64:
    movs r0, #1
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x46
    movs r2, #0x13
    b .L0804A1B8
.L08049D76:
    movs r0, #2
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x47
    movs r2, #0x13
    b .L0804A1B8
.L08049D88:
    movs r0, #3
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x49
    movs r2, #0x13
    b .L0804A1B8
.L08049D9A:
    movs r0, #4
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x4a
    movs r2, #0x13
    b .L0804A1B8
.L08049DAC:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x4b
    movs r2, #0x13
    b .L0804A1B8
.L08049DBE:
    movs r0, #6
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x4c
    movs r2, #0x13
    b .L0804A1B8
.L08049DD0:
    movs r0, #1
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x4e
    movs r2, #3
    b .L0804A1B8
.L08049DE2:
    movs r0, #2
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x4f
    movs r2, #3
    b .L0804A1B8
.L08049DF4:
    movs r0, #3
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x50
    movs r2, #3
    b .L0804A1B8
.L08049E06:
    movs r0, #4
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x52
    movs r2, #3
    b .L0804A1B8
.L08049E18:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x54
    movs r2, #3
    b .L0804A1B8
.L08049E2A:
    movs r0, #6
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x55
    movs r2, #3
    b .L0804A1B8
.L08049E3C:
    movs r0, #1
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x57
    movs r2, #0x19
    b .L0804A1B8
.L08049E4E:
    movs r0, #2
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x58
    movs r2, #0x19
    b .L0804A1B8
.L08049E60:
    movs r0, #3
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x5a
    movs r2, #0x19
    b .L0804A1B8
.L08049E72:
    movs r0, #4
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x5c
    movs r2, #0x19
    b .L0804A1B8
.L08049E84:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x5e
    movs r2, #0x19
    b .L0804A1B8
.L08049E96:
    movs r0, #6
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x5f
    movs r2, #0x19
    b .L0804A1B8
.L08049EA8:
    movs r0, #1
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x61
    movs r2, #0xc
    b .L0804A1B8
.L08049EBA:
    movs r0, #2
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x62
    movs r2, #0xc
    b .L0804A1B8
.L08049ECC:
    movs r0, #3
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x64
    movs r2, #0xc
    b .L0804A1B8
.L08049EDE:
    movs r0, #4
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x65
    movs r2, #0xc
    b .L0804A1B8
.L08049EF0:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x66
    movs r2, #0xc
    b .L0804A1B8
.L08049F02:
    movs r0, #6
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x67
    movs r2, #0xc
    b .L0804A1B8
.L08049F14:
    movs r0, #1
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x69
    b .L0804A1B6
.L08049F24:
    movs r0, #2
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x6a
    b .L0804A1B6
.L08049F34:
    movs r0, #3
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x6b
    b .L0804A1B6
.L08049F44:
    movs r0, #4
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x6d
    b .L0804A1B6
.L08049F54:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x6e
    b .L0804A1B6
.L08049F64:
    movs r0, #6
    str r0, [sp]
    add r1, sp, #4
    movs r0, #0
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x6f
    b .L0804A1B6
.L08049F74:
    movs r1, #0xb9
    lsls r1, r1, #1
    movs r0, #5
    str r0, [sp]
    add r2, sp, #4
    movs r0, #0
    strb r0, [r2]
    adds r0, r7, #0
    movs r2, #0x1f
    b .L0804A1B8
.L08049F88:
    ldr r1, .L08049F9C @ =0x00000173
    movs r0, #6
    str r0, [sp]
    add r2, sp, #4
    movs r0, #0
    strb r0, [r2]
    adds r0, r7, #0
    movs r2, #0x1f
    b .L0804A1B8
    .align 2, 0
.L08049F9C: .word 0x00000173
.L08049FA0:
    movs r1, #1
    str r1, [sp]
    add r0, sp, #4
    strb r1, [r0]
    adds r0, r7, #0
    movs r1, #0x71
    movs r2, #0x13
    b .L0804A1B8
.L08049FB0:
    movs r0, #2
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x72
    movs r2, #0x13
    b .L0804A1B8
.L08049FC2:
    movs r0, #3
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x73
    movs r2, #0x13
    b .L0804A1B8
.L08049FD4:
    movs r0, #4
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x74
    movs r2, #0x13
    b .L0804A1B8
.L08049FE6:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x75
    movs r2, #0x13
    b .L0804A1B8
.L08049FF8:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x76
    movs r2, #0x13
    b .L0804A1B8
.L0804A00A:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x77
    movs r2, #0x13
    b .L0804A1B8
.L0804A01C:
    movs r1, #1
    str r1, [sp]
    add r0, sp, #4
    strb r1, [r0]
    adds r0, r7, #0
    movs r1, #0x7a
    movs r2, #3
    b .L0804A1B8
.L0804A02C:
    movs r0, #2
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x7b
    movs r2, #3
    b .L0804A1B8
.L0804A03E:
    movs r0, #3
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x7c
    movs r2, #3
    b .L0804A1B8
.L0804A050:
    movs r0, #4
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x7d
    movs r2, #3
    b .L0804A1B8
.L0804A062:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x7e
    movs r2, #3
    b .L0804A1B8
.L0804A074:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x7f
    movs r2, #3
    b .L0804A1B8
.L0804A086:
    movs r1, #1
    str r1, [sp]
    add r0, sp, #4
    strb r1, [r0]
    adds r0, r7, #0
    movs r1, #0x82
    movs r2, #0x19
    b .L0804A1B8
.L0804A096:
    movs r0, #2
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x83
    movs r2, #0x19
    b .L0804A1B8
.L0804A0A8:
    movs r0, #3
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x84
    movs r2, #0x19
    b .L0804A1B8
.L0804A0BA:
    movs r0, #4
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x85
    movs r2, #0x19
    b .L0804A1B8
.L0804A0CC:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x86
    movs r2, #0x19
    b .L0804A1B8
.L0804A0DE:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x87
    movs r2, #0x19
    b .L0804A1B8
.L0804A0F0:
    movs r1, #1
    str r1, [sp]
    add r0, sp, #4
    strb r1, [r0]
    adds r0, r7, #0
    movs r1, #0x8a
    movs r2, #0xc
    b .L0804A1B8
.L0804A100:
    movs r0, #2
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x8b
    movs r2, #0xc
    b .L0804A1B8
.L0804A112:
    movs r0, #3
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x8c
    movs r2, #0xc
    b .L0804A1B8
.L0804A124:
    movs r0, #4
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x8d
    movs r2, #0xc
    b .L0804A1B8
.L0804A136:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x8e
    movs r2, #0xc
    b .L0804A1B8
.L0804A148:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x8f
    movs r2, #0xc
    b .L0804A1B8
.L0804A15A:
    movs r1, #1
    str r1, [sp]
    add r0, sp, #4
    strb r1, [r0]
    adds r0, r7, #0
    movs r1, #0x92
    b .L0804A1B6
.L0804A168:
    movs r0, #2
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x93
    b .L0804A1B6
.L0804A178:
    movs r0, #3
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x94
    b .L0804A1B6
.L0804A188:
    movs r0, #4
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x95
    b .L0804A1B6
.L0804A198:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x96
    b .L0804A1B6
.L0804A1A8:
    movs r0, #5
    str r0, [sp]
    add r1, sp, #4
    movs r0, #1
    strb r0, [r1]
    adds r0, r7, #0
    movs r1, #0x97
.L0804A1B6:
    movs r2, #0x15
.L0804A1B8:
    adds r3, r6, #0
    bl UpdateScriptRomanceEvent
    bl .L0804DA2E
.L0804A1C2:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r7, r2
    ldr r1, [r0]
    ldr r0, .L0804A1E0 @ =0x0000215A
    adds r1, r1, r0
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A1E0: .word 0x0000215A
.L0804A1E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A1FC @ =0x0000215A
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804A1FC: .word 0x0000215A
.L0804A200:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A21C @ =0x0000215B
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A21C: .word 0x0000215B
.L0804A220:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A238 @ =0x0000215B
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804A238: .word 0x0000215B
.L0804A23C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A258 @ =0x0000215C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A258: .word 0x0000215C
.L0804A25C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A27C @ =0x0000215A
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804A27C: .word 0x0000215A
.L0804A280:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A29C @ =0x0000215A
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A29C: .word 0x0000215A
.L0804A2A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A2BC @ =0x0000215A
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A2BC: .word 0x0000215A
.L0804A2C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A2E0 @ =0x0000215B
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804A2E0: .word 0x0000215B
.L0804A2E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A300 @ =0x0000215B
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #3
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A300: .word 0x0000215B
.L0804A304:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A320 @ =0x0000215B
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A320: .word 0x0000215B
.L0804A324:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A340 @ =0x0000215B
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A340: .word 0x0000215B
.L0804A344:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A364 @ =0x0000215C
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804A364: .word 0x0000215C
.L0804A368:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A384 @ =0x0000215C
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A384: .word 0x0000215C
.L0804A388:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A3A4 @ =0x0000215C
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A3A4: .word 0x0000215C
.L0804A3A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A3C0 @ =0x0000215C
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    bl .L0804DA28
    .align 2, 0
.L0804A3C0: .word 0x0000215C
.L0804A3C4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A3E0 @ =0x0000215D
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #3
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A3E0: .word 0x0000215D
.L0804A3E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A400 @ =0x0000215D
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A400: .word 0x0000215D
.L0804A404:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A420 @ =0x0000215C
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A420: .word 0x0000215C
.L0804A424:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A434 @ =0x0000215C
    bl .L0804DA1A
    .align 2, 0
.L0804A434: .word 0x0000215C
.L0804A438:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A458 @ =0x0000215D
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804A458: .word 0x0000215D
.L0804A45C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A478 @ =0x0000215D
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A478: .word 0x0000215D
.L0804A47C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A498 @ =0x0000215D
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A498: .word 0x0000215D
.L0804A49C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A4B8 @ =0x0000215D
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A4B8: .word 0x0000215D
.L0804A4BC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804A4D8 @ =0x0000215C
    adds r3, r3, r2
    movs r1, #3
    ands r1, r6
    lsls r1, r1, #0xf
    ldr r0, [r3]
    ldr r2, .L0804A4DC @ =0xFFFE7FFF
    bl .L0804CE8E
    .align 2, 0
.L0804A4D8: .word 0x0000215C
.L0804A4DC: .word 0xFFFE7FFF
.L0804A4E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A4FC @ =0x0000215E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A4FC: .word 0x0000215E
.L0804A500:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A51C @ =0x0000215E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A51C: .word 0x0000215E
.L0804A520:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A53C @ =0x0000215E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A53C: .word 0x0000215E
.L0804A540:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A55C @ =0x0000215E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804A560 @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804A55C: .word 0x0000215E
.L0804A560: .word 0xFFFFFE7F
.L0804A564:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A580 @ =0x0000215F
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A580: .word 0x0000215F
.L0804A584:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A5A0 @ =0x0000215F
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A5A0: .word 0x0000215F
.L0804A5A4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A5C0 @ =0x0000215F
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A5C0: .word 0x0000215F
.L0804A5C4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r5, #1
    adds r1, r6, #0
    ands r1, r5
    ldr r2, .L0804A5F4 @ =0x0000215F
    adds r4, r3, r2
    lsls r1, r1, #7
    ldrb r2, [r4]
    movs r0, #0x7f
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #1
    ldr r0, .L0804A5F8 @ =0x00002160
    adds r3, r3, r0
    ands r1, r5
    ldrb r2, [r3]
    movs r0, #2
    rsbs r0, r0, #0
    bl .L0804D106
    .align 2, 0
.L0804A5F4: .word 0x0000215F
.L0804A5F8: .word 0x00002160
.L0804A5FC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A618 @ =0x00002160
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A618: .word 0x00002160
.L0804A61C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A638 @ =0x00002160
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A638: .word 0x00002160
.L0804A63C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A658 @ =0x00002160
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A658: .word 0x00002160
.L0804A65C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A678 @ =0x00002160
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804A67C @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804A678: .word 0x00002160
.L0804A67C: .word 0xFFFFFE7F
.L0804A680:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A69C @ =0x00002161
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A69C: .word 0x00002161
.L0804A6A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A6BC @ =0x00002161
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A6BC: .word 0x00002161
.L0804A6C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A6DC @ =0x00002161
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A6DC: .word 0x00002161
.L0804A6E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804A6FC @ =0x00002160
    adds r3, r3, r2
    movs r1, #3
    ands r1, r6
    lsls r1, r1, #0xf
    ldr r0, [r3]
    ldr r2, .L0804A700 @ =0xFFFE7FFF
    bl .L0804CE8E
    .align 2, 0
.L0804A6FC: .word 0x00002160
.L0804A700: .word 0xFFFE7FFF
.L0804A704:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A720 @ =0x00002162
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A720: .word 0x00002162
.L0804A724:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A740 @ =0x00002162
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A740: .word 0x00002162
.L0804A744:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A760 @ =0x00002162
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A760: .word 0x00002162
.L0804A764:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A780 @ =0x00002162
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804A784 @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804A780: .word 0x00002162
.L0804A784: .word 0xFFFFFE7F
.L0804A788:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A7A4 @ =0x00002163
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A7A4: .word 0x00002163
.L0804A7A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A7C4 @ =0x00002163
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A7C4: .word 0x00002163
.L0804A7C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A7E4 @ =0x00002163
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A7E4: .word 0x00002163
.L0804A7E8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r5, #1
    adds r1, r6, #0
    ands r1, r5
    ldr r2, .L0804A818 @ =0x00002163
    adds r4, r3, r2
    lsls r1, r1, #7
    ldrb r2, [r4]
    movs r0, #0x7f
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #1
    ldr r0, .L0804A81C @ =0x00002164
    adds r3, r3, r0
    ands r1, r5
    ldrb r2, [r3]
    movs r0, #2
    rsbs r0, r0, #0
    bl .L0804D106
    .align 2, 0
.L0804A818: .word 0x00002163
.L0804A81C: .word 0x00002164
.L0804A820:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A83C @ =0x00002164
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A83C: .word 0x00002164
.L0804A840:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A85C @ =0x00002164
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A85C: .word 0x00002164
.L0804A860:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A87C @ =0x00002164
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A87C: .word 0x00002164
.L0804A880:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A89C @ =0x00002164
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804A8A0 @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804A89C: .word 0x00002164
.L0804A8A0: .word 0xFFFFFE7F
.L0804A8A4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A8C0 @ =0x00002165
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A8C0: .word 0x00002165
.L0804A8C4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A8E0 @ =0x00002165
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A8E0: .word 0x00002165
.L0804A8E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A900 @ =0x00002165
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A900: .word 0x00002165
.L0804A904:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804A920 @ =0x00002164
    adds r3, r3, r2
    movs r1, #3
    ands r1, r6
    lsls r1, r1, #0xf
    ldr r0, [r3]
    ldr r2, .L0804A924 @ =0xFFFE7FFF
    bl .L0804CE8E
    .align 2, 0
.L0804A920: .word 0x00002164
.L0804A924: .word 0xFFFE7FFF
.L0804A928:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A944 @ =0x00002166
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A944: .word 0x00002166
.L0804A948:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A964 @ =0x00002166
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A964: .word 0x00002166
.L0804A968:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A984 @ =0x00002166
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A984: .word 0x00002166
.L0804A988:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A9A4 @ =0x00002166
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804A9A8 @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804A9A4: .word 0x00002166
.L0804A9A8: .word 0xFFFFFE7F
.L0804A9AC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A9C8 @ =0x00002167
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A9C8: .word 0x00002167
.L0804A9CC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804A9E8 @ =0x00002167
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804A9E8: .word 0x00002167
.L0804A9EC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AA08 @ =0x00002167
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AA08: .word 0x00002167
.L0804AA0C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r5, #1
    adds r1, r6, #0
    ands r1, r5
    ldr r2, .L0804AA3C @ =0x00002167
    adds r4, r3, r2
    lsls r1, r1, #7
    ldrb r2, [r4]
    movs r0, #0x7f
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #1
    ldr r0, .L0804AA40 @ =0x00002168
    adds r3, r3, r0
    ands r1, r5
    ldrb r2, [r3]
    movs r0, #2
    rsbs r0, r0, #0
    bl .L0804D106
    .align 2, 0
.L0804AA3C: .word 0x00002167
.L0804AA40: .word 0x00002168
.L0804AA44:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AA60 @ =0x00002168
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AA60: .word 0x00002168
.L0804AA64:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AA80 @ =0x00002168
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AA80: .word 0x00002168
.L0804AA84:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AAA0 @ =0x00002168
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AAA0: .word 0x00002168
.L0804AAA4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AAC0 @ =0x00002168
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804AAC4 @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804AAC0: .word 0x00002168
.L0804AAC4: .word 0xFFFFFE7F
.L0804AAC8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AAE8 @ =0x00002197
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804AAE8: .word 0x00002197
.L0804AAEC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AB08 @ =0x00002169
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AB08: .word 0x00002169
.L0804AB0C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AB28 @ =0x00002169
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AB28: .word 0x00002169
.L0804AB2C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AB48 @ =0x00002169
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AB48: .word 0x00002169
.L0804AB4C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804AB68 @ =0x00002168
    adds r3, r3, r2
    movs r1, #3
    ands r1, r6
    lsls r1, r1, #0xf
    ldr r0, [r3]
    ldr r2, .L0804AB6C @ =0xFFFE7FFF
    bl .L0804CE8E
    .align 2, 0
.L0804AB68: .word 0x00002168
.L0804AB6C: .word 0xFFFE7FFF
.L0804AB70:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AB8C @ =0x0000216A
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AB8C: .word 0x0000216A
.L0804AB90:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804ABAC @ =0x0000216A
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804ABAC: .word 0x0000216A
.L0804ABB0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804ABCC @ =0x0000216A
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804ABCC: .word 0x0000216A
.L0804ABD0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804ABEC @ =0x0000216A
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804ABF0 @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804ABEC: .word 0x0000216A
.L0804ABF0: .word 0xFFFFFE7F
.L0804ABF4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AC10 @ =0x0000216B
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AC10: .word 0x0000216B
.L0804AC14:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AC30 @ =0x0000216B
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AC30: .word 0x0000216B
.L0804AC34:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AC50 @ =0x0000216B
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AC50: .word 0x0000216B
.L0804AC54:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r5, #1
    adds r1, r6, #0
    ands r1, r5
    ldr r2, .L0804AC84 @ =0x0000216B
    adds r4, r3, r2
    lsls r1, r1, #7
    ldrb r2, [r4]
    movs r0, #0x7f
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #1
    ldr r0, .L0804AC88 @ =0x0000216C
    adds r3, r3, r0
    ands r1, r5
    ldrb r2, [r3]
    movs r0, #2
    rsbs r0, r0, #0
    bl .L0804D106
    .align 2, 0
.L0804AC84: .word 0x0000216B
.L0804AC88: .word 0x0000216C
.L0804AC8C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804ACA8 @ =0x0000216C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804ACA8: .word 0x0000216C
.L0804ACAC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804ACC8 @ =0x0000216C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804ACC8: .word 0x0000216C
.L0804ACCC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804ACE8 @ =0x0000216C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804ACE8: .word 0x0000216C
.L0804ACEC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AD08 @ =0x0000216C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804AD0C @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804AD08: .word 0x0000216C
.L0804AD0C: .word 0xFFFFFE7F
.L0804AD10:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AD2C @ =0x0000216D
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AD2C: .word 0x0000216D
.L0804AD30:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AD4C @ =0x0000216D
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AD4C: .word 0x0000216D
.L0804AD50:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AD6C @ =0x0000216D
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AD6C: .word 0x0000216D
.L0804AD70:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804AD8C @ =0x0000216C
    adds r3, r3, r2
    movs r1, #3
    ands r1, r6
    lsls r1, r1, #0xf
    ldr r0, [r3]
    ldr r2, .L0804AD90 @ =0xFFFE7FFF
    bl .L0804CE8E
    .align 2, 0
.L0804AD8C: .word 0x0000216C
.L0804AD90: .word 0xFFFE7FFF
.L0804AD94:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804ADB0 @ =0x0000216E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804ADB0: .word 0x0000216E
.L0804ADB4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804ADD0 @ =0x0000216E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804ADD0: .word 0x0000216E
.L0804ADD4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r0, #0xf
    adds r1, r6, #0
    ands r1, r0
    ldr r2, .L0804ADFC @ =0x0000216F
    adds r4, r3, r2
    lsls r1, r1, #4
    ldrb r2, [r4]
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #4
    movs r0, #7
    ldr r2, .L0804AE00 @ =0x00002170
    bl .L0804D0FE
    .align 2, 0
.L0804ADFC: .word 0x0000216F
.L0804AE00: .word 0x00002170
.L0804AE04:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AE20 @ =0x00002170
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AE20: .word 0x00002170
.L0804AE24:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AE40 @ =0x00002170
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AE40: .word 0x00002170
.L0804AE44:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AE60 @ =0x00002170
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804AE64 @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804AE60: .word 0x00002170
.L0804AE64: .word 0xFFFFFE7F
.L0804AE68:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AE84 @ =0x00002171
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AE84: .word 0x00002171
.L0804AE88:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AEA4 @ =0x00002171
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AEA4: .word 0x00002171
.L0804AEA8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AEC4 @ =0x00002171
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AEC4: .word 0x00002171
.L0804AEC8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AEE0 @ =0x00002171
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    bl .L0804DA28
    .align 2, 0
.L0804AEE0: .word 0x00002171
.L0804AEE4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AF04 @ =0x00002172
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804AF04: .word 0x00002172
.L0804AF08:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AF24 @ =0x00002172
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AF24: .word 0x00002172
.L0804AF28:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AF44 @ =0x00002172
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AF44: .word 0x00002172
.L0804AF48:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AF60 @ =0x00002172
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804AF60: .word 0x00002172
.L0804AF64:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AF84 @ =0x00002173
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804AF84: .word 0x00002173
.L0804AF88:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AFA4 @ =0x00002173
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AFA4: .word 0x00002173
.L0804AFA8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AFC4 @ =0x00002173
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804AFC4: .word 0x00002173
.L0804AFC8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804AFE0 @ =0x00002173
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804AFE0: .word 0x00002173
.L0804AFE4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B004 @ =0x00002174
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B004: .word 0x00002174
.L0804B008:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B024 @ =0x00002174
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B024: .word 0x00002174
.L0804B028:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B044 @ =0x00002174
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B044: .word 0x00002174
.L0804B048:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B060 @ =0x00002174
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804B060: .word 0x00002174
.L0804B064:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B084 @ =0x00002175
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B084: .word 0x00002175
.L0804B088:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B0A4 @ =0x00002175
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B0A4: .word 0x00002175
.L0804B0A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B0C4 @ =0x00002175
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B0C4: .word 0x00002175
.L0804B0C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B0E4 @ =0x00002175
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B0E4: .word 0x00002175
.L0804B0E8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B0F8 @ =0x00002175
    bl .L0804DA1A
    .align 2, 0
.L0804B0F8: .word 0x00002175
.L0804B0FC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B114 @ =0x00002175
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    bl .L0804DA28
    .align 2, 0
.L0804B114: .word 0x00002175
.L0804B118:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B138 @ =0x00002176
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B138: .word 0x00002176
.L0804B13C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B158 @ =0x00002176
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B158: .word 0x00002176
.L0804B15C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B178 @ =0x00002176
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B178: .word 0x00002176
.L0804B17C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B198 @ =0x00002176
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B198: .word 0x00002176
.L0804B19C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B1B8 @ =0x00002176
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804B1BC @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804B1B8: .word 0x00002176
.L0804B1BC: .word 0xFFFFFE7F
.L0804B1C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B1DC @ =0x00002177
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B1DC: .word 0x00002177
.L0804B1E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B1FC @ =0x00002177
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B1FC: .word 0x00002177
.L0804B200:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B21C @ =0x00002177
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B21C: .word 0x00002177
.L0804B220:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B238 @ =0x00002177
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804B238: .word 0x00002177
.L0804B23C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B25C @ =0x00002178
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B25C: .word 0x00002178
.L0804B260:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B27C @ =0x00002178
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B27C: .word 0x00002178
.L0804B280:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B29C @ =0x00002178
    adds r1, r1, r2
    movs r0, #7
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x39
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B29C: .word 0x00002178
.L0804B2A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B2B8 @ =0x00002178
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804B2B8: .word 0x00002178
.L0804B2BC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B2DC @ =0x00002179
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B2DC: .word 0x00002179
.L0804B2E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B2FC @ =0x00002179
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B2FC: .word 0x00002179
.L0804B300:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B31C @ =0x00002179
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B31C: .word 0x00002179
.L0804B320:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804B33C @ =0x00002178
    adds r3, r3, r2
    movs r1, #0xf
    ands r1, r6
    lsls r1, r1, #0xe
    ldr r0, [r3]
    ldr r2, .L0804B340 @ =0xFFFC3FFF
    bl .L0804CE8E
    .align 2, 0
.L0804B33C: .word 0x00002178
.L0804B340: .word 0xFFFC3FFF
.L0804B344:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B360 @ =0x0000217A
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B360: .word 0x0000217A
.L0804B364:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B380 @ =0x0000217A
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B380: .word 0x0000217A
.L0804B384:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B3A0 @ =0x0000217A
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B3A0: .word 0x0000217A
.L0804B3A4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B3BC @ =0x0000217A
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    bl .L0804DA28
    .align 2, 0
.L0804B3BC: .word 0x0000217A
.L0804B3C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B3E0 @ =0x0000217B
    adds r1, r1, r2
    movs r0, #0x1f
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B3E0: .word 0x0000217B
.L0804B3E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B400 @ =0x0000217B
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B400: .word 0x0000217B
.L0804B404:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r5, #1
    adds r1, r6, #0
    ands r1, r5
    ldr r2, .L0804B434 @ =0x0000217B
    adds r4, r3, r2
    lsls r1, r1, #7
    ldrb r2, [r4]
    movs r0, #0x7f
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #1
    ldr r0, .L0804B438 @ =0x0000217C
    adds r3, r3, r0
    ands r1, r5
    ldrb r2, [r3]
    movs r0, #2
    rsbs r0, r0, #0
    bl .L0804D106
    .align 2, 0
.L0804B434: .word 0x0000217B
.L0804B438: .word 0x0000217C
.L0804B43C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B458 @ =0x0000217C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B458: .word 0x0000217C
.L0804B45C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B478 @ =0x0000217C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B478: .word 0x0000217C
.L0804B47C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B498 @ =0x0000217C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B498: .word 0x0000217C
.L0804B49C:
    @ Variable 275: preserve bits 0-6 and replace bit 7.
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B4B4 @ =0x0000217C
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    bl .L0804DA28
    .align 2, 0
.L0804B4B4: .word 0x0000217C
.L0804B4B8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B4D8 @ =0x0000217D
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B4D8: .word 0x0000217D
.L0804B4DC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B4F8 @ =0x0000217D
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B4F8: .word 0x0000217D
.L0804B4FC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B518 @ =0x0000217D
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B518: .word 0x0000217D
.L0804B51C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B534 @ =0x0000217D
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804B534: .word 0x0000217D
.L0804B538:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B558 @ =0x0000217E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B558: .word 0x0000217E
.L0804B55C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B578 @ =0x0000217E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B578: .word 0x0000217E
.L0804B57C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B598 @ =0x0000217E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B598: .word 0x0000217E
.L0804B59C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B5B4 @ =0x0000217E
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804B5B4: .word 0x0000217E
.L0804B5B8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B5D8 @ =0x0000217F
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B5D8: .word 0x0000217F
.L0804B5DC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B5F8 @ =0x0000217F
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B5F8: .word 0x0000217F
.L0804B5FC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B618 @ =0x0000217F
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B618: .word 0x0000217F
.L0804B61C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B634 @ =0x0000217F
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804B634: .word 0x0000217F
.L0804B638:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    movs r2, #0x86
    lsls r2, r2, #6
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
.L0804B658:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    movs r2, #0x86
    lsls r2, r2, #6
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
.L0804B676:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    movs r2, #0x86
    lsls r2, r2, #6
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
.L0804B694:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    movs r2, #0x86
    lsls r2, r2, #6
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
.L0804B6AC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B6CC @ =0x00002181
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B6CC: .word 0x00002181
.L0804B6D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B6EC @ =0x00002181
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B6EC: .word 0x00002181
.L0804B6F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B70C @ =0x00002181
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B70C: .word 0x00002181
.L0804B710:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B728 @ =0x00002181
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804B728: .word 0x00002181
.L0804B72C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B74C @ =0x00002182
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B74C: .word 0x00002182
.L0804B750:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B76C @ =0x00002182
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B76C: .word 0x00002182
.L0804B770:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B78C @ =0x00002182
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B78C: .word 0x00002182
.L0804B790:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B7AC @ =0x00002182
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B7AC: .word 0x00002182
.L0804B7B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B7CC @ =0x00002182
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804B7D0 @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804B7CC: .word 0x00002182
.L0804B7D0: .word 0xFFFFFE7F
.L0804B7D4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B7F0 @ =0x00002183
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B7F0: .word 0x00002183
.L0804B7F4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B810 @ =0x00002183
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B810: .word 0x00002183
.L0804B814:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B830 @ =0x00002183
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B830: .word 0x00002183
.L0804B834:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r5, #1
    adds r1, r6, #0
    ands r1, r5
    ldr r2, .L0804B864 @ =0x00002183
    adds r4, r3, r2
    lsls r1, r1, #7
    ldrb r2, [r4]
    movs r0, #0x7f
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #1
    ldr r0, .L0804B868 @ =0x00002184
    adds r3, r3, r0
    ands r1, r5
    ldrb r2, [r3]
    movs r0, #2
    rsbs r0, r0, #0
    bl .L0804D106
    .align 2, 0
.L0804B864: .word 0x00002183
.L0804B868: .word 0x00002184
.L0804B86C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B888 @ =0x00002184
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #3
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B888: .word 0x00002184
.L0804B88C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B8A8 @ =0x00002184
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B8A8: .word 0x00002184
.L0804B8AC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B8C8 @ =0x00002184
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B8C8: .word 0x00002184
.L0804B8CC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B8E4 @ =0x00002184
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804B8E4: .word 0x00002184
.L0804B8E8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B908 @ =0x00002185
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B908: .word 0x00002185
.L0804B90C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B928 @ =0x00002185
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B928: .word 0x00002185
.L0804B92C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B948 @ =0x00002185
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B948: .word 0x00002185
.L0804B94C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B964 @ =0x00002185
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804B964: .word 0x00002185
.L0804B968:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B988 @ =0x00002186
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804B988: .word 0x00002186
.L0804B98C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B9A8 @ =0x00002186
    adds r1, r1, r2
    movs r0, #7
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0x1d
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B9A8: .word 0x00002186
.L0804B9AC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B9C8 @ =0x00002186
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804B9C8: .word 0x00002186
.L0804B9CC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804B9E8 @ =0x00002186
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804B9EC @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804B9E8: .word 0x00002186
.L0804B9EC: .word 0xFFFFFE7F
.L0804B9F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BA0C @ =0x00002187
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BA0C: .word 0x00002187
.L0804BA10:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BA2C @ =0x00002187
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BA2C: .word 0x00002187
.L0804BA30:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BA4C @ =0x00002187
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BA4C: .word 0x00002187
.L0804BA50:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r5, #1
    adds r1, r6, #0
    ands r1, r5
    ldr r2, .L0804BA80 @ =0x00002187
    adds r4, r3, r2
    lsls r1, r1, #7
    ldrb r2, [r4]
    movs r0, #0x7f
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #1
    ldr r0, .L0804BA84 @ =0x00002188
    adds r3, r3, r0
    ands r1, r5
    ldrb r2, [r3]
    movs r0, #2
    rsbs r0, r0, #0
    bl .L0804D106
    .align 2, 0
.L0804BA80: .word 0x00002187
.L0804BA84: .word 0x00002188
.L0804BA88:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BAA4 @ =0x00002188
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BAA4: .word 0x00002188
.L0804BAA8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BAC4 @ =0x00002188
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BAC4: .word 0x00002188
.L0804BAC8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BAE4 @ =0x00002188
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BAE4: .word 0x00002188
.L0804BAE8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BB04 @ =0x00002188
    adds r1, r1, r2
    movs r0, #7
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804BB08 @ =0xFFFFFC7F
    bl .L0804D2D6
    .align 2, 0
.L0804BB04: .word 0x00002188
.L0804BB08: .word 0xFFFFFC7F
.L0804BB0C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BB28 @ =0x00002189
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BB28: .word 0x00002189
.L0804BB2C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BB48 @ =0x00002189
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BB48: .word 0x00002189
.L0804BB4C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804BB68 @ =0x00002188
    adds r3, r3, r2
    movs r1, #0xf
    ands r1, r6
    lsls r1, r1, #0xe
    ldr r0, [r3]
    ldr r2, .L0804BB6C @ =0xFFFC3FFF
    bl .L0804CE8E
    .align 2, 0
.L0804BB68: .word 0x00002188
.L0804BB6C: .word 0xFFFC3FFF
.L0804BB70:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BB8C @ =0x0000218A
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BB8C: .word 0x0000218A
.L0804BB90:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BBAC @ =0x0000218A
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BBAC: .word 0x0000218A
.L0804BBB0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BBC8 @ =0x0000218A
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804BBC8: .word 0x0000218A
.L0804BBCC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BBEC @ =0x0000218B
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804BBEC: .word 0x0000218B
.L0804BBF0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BC0C @ =0x0000218B
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BC0C: .word 0x0000218B
.L0804BC10:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r1, #7
    ands r1, r6
    ldr r2, .L0804BC40 @ =0x0000218B
    adds r4, r3, r2
    lsls r1, r1, #5
    ldrb r2, [r4]
    movs r0, #0x1f
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #3
    movs r0, #1
    ldr r2, .L0804BC44 @ =0x0000218C
    adds r3, r3, r2
    ands r1, r0
    ldrb r2, [r3]
    subs r0, #3
    bl .L0804D106
    .align 2, 0
.L0804BC40: .word 0x0000218B
.L0804BC44: .word 0x0000218C
.L0804BC48:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BC64 @ =0x0000218C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BC64: .word 0x0000218C
.L0804BC68:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BC84 @ =0x0000218C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BC84: .word 0x0000218C
.L0804BC88:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BCA4 @ =0x0000218C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BCA4: .word 0x0000218C
.L0804BCA8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BCC4 @ =0x0000218C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804BCC8 @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804BCC4: .word 0x0000218C
.L0804BCC8: .word 0xFFFFFE7F
.L0804BCCC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BCE8 @ =0x0000218D
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BCE8: .word 0x0000218D
.L0804BCEC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BD08 @ =0x0000218D
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BD08: .word 0x0000218D
.L0804BD0C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804BD28 @ =0x0000218C
    adds r3, r3, r2
    movs r1, #0xf
    ands r1, r6
    lsls r1, r1, #0xd
    ldr r0, [r3]
    ldr r2, .L0804BD2C @ =0xFFFE1FFF
    bl .L0804CE8E
    .align 2, 0
.L0804BD28: .word 0x0000218C
.L0804BD2C: .word 0xFFFE1FFF
.L0804BD30:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BD4C @ =0x0000218E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BD4C: .word 0x0000218E
.L0804BD50:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BD6C @ =0x0000218E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BD6C: .word 0x0000218E
.L0804BD70:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BD8C @ =0x0000218E
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BD8C: .word 0x0000218E
.L0804BD90:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BDA8 @ =0x0000218E
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804BDA8: .word 0x0000218E
.L0804BDAC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BDCC @ =0x0000218F
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804BDCC: .word 0x0000218F
.L0804BDD0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BDEC @ =0x0000218F
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BDEC: .word 0x0000218F
.L0804BDF0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BE0C @ =0x0000218F
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BE0C: .word 0x0000218F
.L0804BE10:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BE28 @ =0x0000218F
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804BE28: .word 0x0000218F
.L0804BE2C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BE4C @ =0x00002190
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804BE4C: .word 0x00002190
.L0804BE50:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BE6C @ =0x00002190
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BE6C: .word 0x00002190
.L0804BE70:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BE8C @ =0x00002190
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BE8C: .word 0x00002190
.L0804BE90:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BEA8 @ =0x00002190
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804BEA8: .word 0x00002190
.L0804BEAC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BECC @ =0x00002191
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804BECC: .word 0x00002191
.L0804BED0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BEEC @ =0x00002191
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BEEC: .word 0x00002191
.L0804BEF0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BF0C @ =0x00002191
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BF0C: .word 0x00002191
.L0804BF10:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BF28 @ =0x00002191
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804BF28: .word 0x00002191
.L0804BF2C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BF4C @ =0x00002192
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804BF4C: .word 0x00002192
.L0804BF50:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BF6C @ =0x00002192
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BF6C: .word 0x00002192
.L0804BF70:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BF8C @ =0x00002192
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BF8C: .word 0x00002192
.L0804BF90:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BFA8 @ =0x00002192
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804BFA8: .word 0x00002192
.L0804BFAC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BFCC @ =0x00002193
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804BFCC: .word 0x00002193
.L0804BFD0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804BFEC @ =0x00002193
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804BFEC: .word 0x00002193
.L0804BFF0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C00C @ =0x00002193
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C00C: .word 0x00002193
.L0804C010:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C028 @ =0x00002193
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804C028: .word 0x00002193
.L0804C02C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C04C @ =0x00002194
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804C04C: .word 0x00002194
.L0804C050:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C06C @ =0x00002194
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C06C: .word 0x00002194
.L0804C070:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C08C @ =0x00002194
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C08C: .word 0x00002194
.L0804C090:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C0A8 @ =0x00002194
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804C0A8: .word 0x00002194
.L0804C0AC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C0CC @ =0x00002195
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804C0CC: .word 0x00002195
.L0804C0D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C0E8 @ =0x00002195
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804C0E8: .word 0x00002195
.L0804C0EC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C10C @ =0x00002196
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804C10C: .word 0x00002196
.L0804C110:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C12C @ =0x00002196
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C12C: .word 0x00002196
.L0804C130:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C14C @ =0x00002196
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C14C: .word 0x00002196
.L0804C150:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C168 @ =0x00002196
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804C168: .word 0x00002196
.L0804C16C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C188 @ =0x00002197
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C188: .word 0x00002197
.L0804C18C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C1A8 @ =0x00002197
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C1A8: .word 0x00002197
.L0804C1AC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C1C4 @ =0x00002197
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804C1C4: .word 0x00002197
.L0804C1C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C1E8 @ =0x00002198
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804C1E8: .word 0x00002198
.L0804C1EC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C208 @ =0x00002198
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C208: .word 0x00002198
.L0804C20C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C228 @ =0x00002198
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C228: .word 0x00002198
.L0804C22C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C244 @ =0x00002198
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804C244: .word 0x00002198
.L0804C248:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C268 @ =0x00002199
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804C268: .word 0x00002199
.L0804C26C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C288 @ =0x00002199
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C288: .word 0x00002199
.L0804C28C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C2A8 @ =0x00002199
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C2A8: .word 0x00002199
.L0804C2AC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C2C8 @ =0x00002199
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C2C8: .word 0x00002199
.L0804C2CC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C2E8 @ =0x00002199
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C2E8: .word 0x00002199
.L0804C2EC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C2FC @ =0x00002199
    bl .L0804DA1A
    .align 2, 0
.L0804C2FC: .word 0x00002199
.L0804C300:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804C31C @ =0x00002198
    adds r3, r3, r2
    movs r1, #3
    ands r1, r6
    lsls r1, r1, #0xf
    ldr r0, [r3]
    ldr r2, .L0804C320 @ =0xFFFE7FFF
    bl .L0804CE8E
    .align 2, 0
.L0804C31C: .word 0x00002198
.L0804C320: .word 0xFFFE7FFF
.L0804C324:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C340 @ =0x0000219A
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C340: .word 0x0000219A
.L0804C344:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C360 @ =0x0000219A
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C360: .word 0x0000219A
.L0804C364:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C380 @ =0x0000219A
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804C384 @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804C380: .word 0x0000219A
.L0804C384: .word 0xFFFFFE7F
.L0804C388:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C3A4 @ =0x0000219B
    adds r1, r1, r2
    movs r0, #7
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #0xf
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C3A4: .word 0x0000219B
.L0804C3A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C3C4 @ =0x0000219B
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C3C4: .word 0x0000219B
.L0804C3C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C3D8 @ =0x0000219B
    bl .L0804DA1A
    .align 2, 0
.L0804C3D8: .word 0x0000219B
.L0804C3DC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r1, #1
    ands r1, r6
    ldr r2, .L0804C40C @ =0x0000219B
    adds r4, r3, r2
    lsls r1, r1, #7
    ldrb r2, [r4]
    movs r0, #0x7f
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #1
    movs r0, #3
    ldr r2, .L0804C410 @ =0x0000219C
    adds r3, r3, r2
    ands r1, r0
    ldrb r2, [r3]
    subs r0, #7
    bl .L0804D106
    .align 2, 0
.L0804C40C: .word 0x0000219B
.L0804C410: .word 0x0000219C
.L0804C414:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C430 @ =0x0000219C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C430: .word 0x0000219C
.L0804C434:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C450 @ =0x0000219C
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C450: .word 0x0000219C
.L0804C454:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C474 @ =0x0000219D
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804C474: .word 0x0000219D
.L0804C478:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C494 @ =0x0000219D
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C494: .word 0x0000219D
.L0804C498:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C4B4 @ =0x0000219D
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C4B4: .word 0x0000219D
.L0804C4B8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C4D0 @ =0x0000219D
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804C4D0: .word 0x0000219D
.L0804C4D4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C4F4 @ =0x0000219E
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804C4F4: .word 0x0000219E
.L0804C4F8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C514 @ =0x0000219E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C514: .word 0x0000219E
.L0804C518:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C534 @ =0x0000219E
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C534: .word 0x0000219E
.L0804C538:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C554 @ =0x0000219E
    adds r1, r1, r2
    movs r0, #7
    ands r6, r0
    lsls r3, r6, #6
    ldrh r2, [r1]
    ldr r0, .L0804C558 @ =0xFFFFFE3F
    bl .L0804D2D6
    .align 2, 0
.L0804C554: .word 0x0000219E
.L0804C558: .word 0xFFFFFE3F
.L0804C55C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C578 @ =0x0000219F
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C578: .word 0x0000219F
.L0804C57C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C598 @ =0x0000219F
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C598: .word 0x0000219F
.L0804C59C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C5B8 @ =0x0000219F
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C5B8: .word 0x0000219F
.L0804C5BC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C5D4 @ =0x0000219F
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804C5D4: .word 0x0000219F
.L0804C5D8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C5F8 @ =0x000021A0
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804C5F8: .word 0x000021A0
.L0804C5FC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C618 @ =0x000021A0
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C618: .word 0x000021A0
.L0804C61C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C638 @ =0x000021A0
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C638: .word 0x000021A0
.L0804C63C:
    @ Variable 423: preserve all other bits and replace bit 4 with one-bit input.
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C658 @ =0x000021A0
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C658: .word 0x000021A0
.L0804C65C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C678 @ =0x000021A0
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C678: .word 0x000021A0
.L0804C67C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C698 @ =0x000021CA
    adds r1, r1, r2
    movs r0, #7
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804C69C @ =0xFFFFFC7F
    bl .L0804D2D6
    .align 2, 0
.L0804C698: .word 0x000021CA
.L0804C69C: .word 0xFFFFFC7F
.L0804C6A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C6C0 @ =0x000021A1
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804C6C0: .word 0x000021A1
.L0804C6C4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C6E0 @ =0x000021A1
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C6E0: .word 0x000021A1
.L0804C6E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C6FC @ =0x000021A1
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804C6FC: .word 0x000021A1
.L0804C700:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C720 @ =0x000021A2
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804C720: .word 0x000021A2
.L0804C724:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C740 @ =0x000021A2
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C740: .word 0x000021A2
.L0804C744:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C760 @ =0x000021A2
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C760: .word 0x000021A2
.L0804C764:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C77C @ =0x000021A2
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    bl .L0804DA28
    .align 2, 0
.L0804C77C: .word 0x000021A2
.L0804C780:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C7A0 @ =0x000021A3
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804C7A0: .word 0x000021A3
.L0804C7A4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C7C0 @ =0x000021A3
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C7C0: .word 0x000021A3
.L0804C7C4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C7E0 @ =0x000021A3
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C7E0: .word 0x000021A3
.L0804C7E4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C7F4 @ =0x000021A3
    bl .L0804DA1A
    .align 2, 0
.L0804C7F4: .word 0x000021A3
.L0804C7F8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r5, #1
    adds r1, r6, #0
    ands r1, r5
    ldr r2, .L0804C828 @ =0x000021A3
    adds r4, r3, r2
    lsls r1, r1, #7
    ldrb r2, [r4]
    movs r0, #0x7f
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #1
    ldr r0, .L0804C82C @ =0x000021A4
    adds r3, r3, r0
    ands r1, r5
    ldrb r2, [r3]
    movs r0, #2
    rsbs r0, r0, #0
    bl .L0804D106
    .align 2, 0
.L0804C828: .word 0x000021A3
.L0804C82C: .word 0x000021A4
.L0804C830:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C84C @ =0x000021A4
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #3
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C84C: .word 0x000021A4
.L0804C850:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C86C @ =0x000021A4
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C86C: .word 0x000021A4
.L0804C870:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C88C @ =0x000021A4
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C88C: .word 0x000021A4
.L0804C890:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C8AC @ =0x000021A4
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C8AC: .word 0x000021A4
.L0804C8B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C8C8 @ =0x000021A4
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    bl .L0804DA28
    .align 2, 0
.L0804C8C8: .word 0x000021A4
.L0804C8CC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C8EC @ =0x000021A5
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804C8EC: .word 0x000021A5
.L0804C8F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C90C @ =0x000021A5
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C90C: .word 0x000021A5
.L0804C910:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C92C @ =0x000021A5
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C92C: .word 0x000021A5
.L0804C930:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C94C @ =0x000021A5
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C94C: .word 0x000021A5
.L0804C950:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804C968 @ =0x000021A4
    adds r3, r3, r2
    movs r1, #7
    ands r1, r6
    lsls r1, r1, #0xf
    ldr r0, [r3]
    ldr r2, .L0804C96C @ =0xFFFC7FFF
    b .L0804CE8E
    .align 2, 0
.L0804C968: .word 0x000021A4
.L0804C96C: .word 0xFFFC7FFF
.L0804C970:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C98C @ =0x000021A6
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C98C: .word 0x000021A6
.L0804C990:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C9AC @ =0x000021A6
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C9AC: .word 0x000021A6
.L0804C9B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C9CC @ =0x000021A6
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C9CC: .word 0x000021A6
.L0804C9D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804C9EC @ =0x000021A6
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804C9EC: .word 0x000021A6
.L0804C9F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CA00 @ =0x000021A6
    bl .L0804DA1A
    .align 2, 0
.L0804CA00: .word 0x000021A6
.L0804CA04:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CA20 @ =0x000021A6
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804CA24 @ =0xFFFFFE7F
    bl .L0804D2D6
    .align 2, 0
.L0804CA20: .word 0x000021A6
.L0804CA24: .word 0xFFFFFE7F
.L0804CA28:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CA44 @ =0x000021A7
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CA44: .word 0x000021A7
.L0804CA48:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CA64 @ =0x000021A7
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CA64: .word 0x000021A7
.L0804CA68:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CA84 @ =0x000021A7
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x61
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CA84: .word 0x000021A7
.L0804CA88:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r5, #1
    adds r1, r6, #0
    ands r1, r5
    ldr r2, .L0804CAB8 @ =0x000021A7
    adds r4, r3, r2
    lsls r1, r1, #7
    ldrb r2, [r4]
    movs r0, #0x7f
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #1
    ldr r0, .L0804CABC @ =0x000021A8
    adds r3, r3, r0
    ands r1, r5
    ldrb r2, [r3]
    movs r0, #2
    rsbs r0, r0, #0
    b .L0804D106
    .align 2, 0
.L0804CAB8: .word 0x000021A7
.L0804CABC: .word 0x000021A8
.L0804CAC0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CADC @ =0x000021A8
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CADC: .word 0x000021A8
.L0804CAE0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CAFC @ =0x000021A8
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x19
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CAFC: .word 0x000021A8
.L0804CB00:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CB18 @ =0x000021A8
    adds r1, r1, r2
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x1f
    bl .L0804DA28
    .align 2, 0
.L0804CB18: .word 0x000021A8
.L0804CB1C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CB3C @ =0x000021A9
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804CB3C: .word 0x000021A9
.L0804CB40:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CB5C @ =0x000021A9
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CB5C: .word 0x000021A9
.L0804CB60:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CB7C @ =0x000021A9
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CB7C: .word 0x000021A9
.L0804CB80:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CB9C @ =0x000021A9
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CB9C: .word 0x000021A9
.L0804CBA0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CBB0 @ =0x000021A9
    bl .L0804DA1A
    .align 2, 0
.L0804CBB0: .word 0x000021A9
.L0804CBB4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CBCC @ =0x000021A9
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    bl .L0804DA28
    .align 2, 0
.L0804CBCC: .word 0x000021A9
.L0804CBD0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CBF0 @ =0x000021AA
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804CBF0: .word 0x000021AA
.L0804CBF4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CC10 @ =0x000021AA
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #3
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CC10: .word 0x000021AA
.L0804CC14:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CC30 @ =0x000021AA
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CC30: .word 0x000021AA
.L0804CC34:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CC50 @ =0x000021AA
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CC50: .word 0x000021AA
.L0804CC54:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CC70 @ =0x000021AA
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CC70: .word 0x000021AA
.L0804CC74:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CC90 @ =0x000021AA
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CC90: .word 0x000021AA
.L0804CC94:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CCA4 @ =0x000021AA
    bl .L0804DA1A
    .align 2, 0
.L0804CCA4: .word 0x000021AA
.L0804CCA8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CCC0 @ =0x000021AA
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    bl .L0804DA28
    .align 2, 0
.L0804CCC0: .word 0x000021AA
.L0804CCC4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CCE4 @ =0x000021AB
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804CCE4: .word 0x000021AB
.L0804CCE8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CD04 @ =0x000021AB
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #3
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CD04: .word 0x000021AB
.L0804CD08:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CD24 @ =0x000021AB
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CD24: .word 0x000021AB
.L0804CD28:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CD44 @ =0x000021AB
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CD44: .word 0x000021AB
.L0804CD48:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CD60 @ =0x000021B4
    adds r1, r1, r2
    movs r0, #0xff
    ands r6, r0
    lsls r3, r6, #6
    ldrh r2, [r1]
    ldr r0, .L0804CD64 @ =0xFFFFC03F
    b .L0804D2D6
    .align 2, 0
.L0804CD60: .word 0x000021B4
.L0804CD64: .word 0xFFFFC03F
.L0804CD68:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804CD74 @ =0x000021B4
    b .L0804CE82
    .align 2, 0
.L0804CD74: .word 0x000021B4
.L0804CD78:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CD90 @ =0x000021B6
    adds r1, r1, r2
    movs r0, #0xff
    ands r6, r0
    lsls r3, r6, #6
    ldrh r2, [r1]
    ldr r0, .L0804CD94 @ =0xFFFFC03F
    b .L0804D2D6
    .align 2, 0
.L0804CD90: .word 0x000021B6
.L0804CD94: .word 0xFFFFC03F
.L0804CD98:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r1, #3
    ands r1, r6
    ldr r2, .L0804CDC8 @ =0x000021B7
    adds r4, r3, r2
    lsls r1, r1, #6
    ldrb r2, [r4]
    movs r5, #0x3f
    adds r0, r5, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #2
    ldr r0, .L0804CDCC @ =0x000021B8
    adds r3, r3, r0
    ands r1, r5
    ldrb r2, [r3]
    movs r0, #0x40
    rsbs r0, r0, #0
    b .L0804D106
    .align 2, 0
.L0804CDC8: .word 0x000021B7
.L0804CDCC: .word 0x000021B8
.L0804CDD0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CDE8 @ =0x000021B8
    adds r1, r1, r2
    movs r0, #0xff
    ands r6, r0
    lsls r3, r6, #6
    ldrh r2, [r1]
    ldr r0, .L0804CDEC @ =0xFFFFC03F
    b .L0804D2D6
    .align 2, 0
.L0804CDE8: .word 0x000021B8
.L0804CDEC: .word 0xFFFFC03F
.L0804CDF0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804CDFC @ =0x000021B8
    b .L0804CE82
    .align 2, 0
.L0804CDFC: .word 0x000021B8
.L0804CE00:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CE18 @ =0x000021BA
    adds r1, r1, r2
    movs r0, #0xff
    ands r6, r0
    lsls r3, r6, #6
    ldrh r2, [r1]
    ldr r0, .L0804CE1C @ =0xFFFFC03F
    b .L0804D2D6
    .align 2, 0
.L0804CE18: .word 0x000021BA
.L0804CE1C: .word 0xFFFFC03F
.L0804CE20:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r1, #3
    ands r1, r6
    ldr r2, .L0804CE50 @ =0x000021BB
    adds r4, r3, r2
    lsls r1, r1, #6
    ldrb r2, [r4]
    movs r5, #0x3f
    adds r0, r5, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #2
    ldr r0, .L0804CE54 @ =0x000021BC
    adds r3, r3, r0
    ands r1, r5
    ldrb r2, [r3]
    movs r0, #0x40
    rsbs r0, r0, #0
    b .L0804D106
    .align 2, 0
.L0804CE50: .word 0x000021BB
.L0804CE54: .word 0x000021BC
.L0804CE58:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CE70 @ =0x000021BC
    adds r1, r1, r2
    movs r0, #0xff
    ands r6, r0
    lsls r3, r6, #6
    ldrh r2, [r1]
    ldr r0, .L0804CE74 @ =0xFFFFC03F
    b .L0804D2D6
    .align 2, 0
.L0804CE70: .word 0x000021BC
.L0804CE74: .word 0xFFFFC03F
.L0804CE78:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    ldr r2, .L0804CE98 @ =0x000021BC
.L0804CE82:
    adds r3, r3, r2
    movs r1, #0xff
    ands r1, r6
    lsls r1, r1, #0xe
    ldr r0, [r3]
    ldr r2, .L0804CE9C @ =0xFFC03FFF
.L0804CE8E:
    ands r0, r2
    orrs r0, r1
    str r0, [r3]
    bl .L0804DA2E
    .align 2, 0
.L0804CE98: .word 0x000021BC
.L0804CE9C: .word 0xFFC03FFF
.L0804CEA0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CEB8 @ =0x000021BE
    adds r1, r1, r2
    movs r0, #0xff
    ands r6, r0
    lsls r3, r6, #6
    ldrh r2, [r1]
    ldr r0, .L0804CEBC @ =0xFFFFC03F
    b .L0804D2D6
    .align 2, 0
.L0804CEB8: .word 0x000021BE
.L0804CEBC: .word 0xFFFFC03F
.L0804CEC0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r1, #3
    ands r1, r6
    ldr r2, .L0804CEF0 @ =0x000021BF
    adds r4, r3, r2
    lsls r1, r1, #6
    ldrb r2, [r4]
    movs r5, #0x3f
    adds r0, r5, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #2
    movs r0, #0x87
    lsls r0, r0, #6
    adds r3, r3, r0
    ands r1, r5
    ldrb r2, [r3]
    movs r0, #0x40
    rsbs r0, r0, #0
    b .L0804D106
    .align 2, 0
.L0804CEF0: .word 0x000021BF
.L0804CEF4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    movs r2, #0x87
    lsls r2, r2, #6
    adds r1, r1, r2
    movs r0, #7
    ands r6, r0
    lsls r3, r6, #6
    ldrh r2, [r1]
    ldr r0, .L0804CF10 @ =0xFFFFFE3F
    b .L0804D2D6
    .align 2, 0
.L0804CF10: .word 0xFFFFFE3F
.L0804CF14:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CF30 @ =0x000021C1
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #7
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CF30: .word 0x000021C1
.L0804CF34:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CF50 @ =0x000021C1
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CF50: .word 0x000021C1
.L0804CF54:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CF70 @ =0x000021C1
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CF70: .word 0x000021C1
.L0804CF74:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CF90 @ =0x000021C1
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804CF90: .word 0x000021C1
.L0804CF94:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CFA4 @ =0x000021C1
    bl .L0804DA1A
    .align 2, 0
.L0804CFA4: .word 0x000021C1
.L0804CFA8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CFC0 @ =0x000021C1
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    bl .L0804DA28
    .align 2, 0
.L0804CFC0: .word 0x000021C1
.L0804CFC4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804CFE4 @ =0x000021C2
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804CFE4: .word 0x000021C2
.L0804CFE8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D004 @ =0x000021C2
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #3
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D004: .word 0x000021C2
.L0804D008:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D024 @ =0x000021C2
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D024: .word 0x000021C2
.L0804D028:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D044 @ =0x000021C2
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D044: .word 0x000021C2
.L0804D048:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D064 @ =0x000021C2
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D064: .word 0x000021C2
.L0804D068:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D084 @ =0x000021C2
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D084: .word 0x000021C2
.L0804D088:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D098 @ =0x000021C2
    bl .L0804DA1A
    .align 2, 0
.L0804D098: .word 0x000021C2
.L0804D09C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D0B4 @ =0x000021C2
    adds r1, r1, r2
    movs r0, #0xf
    ands r6, r0
    lsls r3, r6, #7
    ldrh r2, [r1]
    ldr r0, .L0804D0B8 @ =0xFFFFF87F
    b .L0804D2D6
    .align 2, 0
.L0804D0B4: .word 0x000021C2
.L0804D0B8: .word 0xFFFFF87F
.L0804D0BC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D0D8 @ =0x000021C3
    adds r1, r1, r2
    movs r0, #0xf
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #0x79
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D0D8: .word 0x000021C3
.L0804D0DC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r3, [r0]
    movs r1, #1
    ands r1, r6
    ldr r2, .L0804D110 @ =0x000021C3
    adds r4, r3, r2
    lsls r1, r1, #7
    ldrb r2, [r4]
    movs r0, #0x7f
    ands r0, r2
    orrs r0, r1
    strb r0, [r4]
    lsrs r1, r6, #1
    movs r0, #7
    ldr r2, .L0804D114 @ =0x000021C4
.L0804D0FE:
    adds r3, r3, r2
    ands r1, r0
    ldrb r2, [r3]
    subs r0, #0xf
.L0804D106:
    ands r0, r2
    orrs r0, r1
    strb r0, [r3]
    bl .L0804DA2E
    .align 2, 0
.L0804D110: .word 0x000021C3
.L0804D114: .word 0x000021C4
.L0804D118:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D134 @ =0x000021C4
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D134: .word 0x000021C4
.L0804D138:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D154 @ =0x000021C4
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D154: .word 0x000021C4
.L0804D158:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D174 @ =0x000021C4
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D174: .word 0x000021C4
.L0804D178:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D188 @ =0x000021C4
    bl .L0804DA1A
    .align 2, 0
.L0804D188: .word 0x000021C4
.L0804D18C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D1A4 @ =0x000021C4
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    bl .L0804DA28
    .align 2, 0
.L0804D1A4: .word 0x000021C4
.L0804D1A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D1C8 @ =0x000021C5
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804D1C8: .word 0x000021C5
.L0804D1CC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D1E8 @ =0x000021C5
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #3
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D1E8: .word 0x000021C5
.L0804D1EC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D208 @ =0x000021C5
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D208: .word 0x000021C5
.L0804D20C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D228 @ =0x000021C5
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D228: .word 0x000021C5
.L0804D22C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D248 @ =0x000021C5
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D248: .word 0x000021C5
.L0804D24C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D268 @ =0x000021C5
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    bl .L0804DA28
    .align 2, 0
.L0804D268: .word 0x000021C5
.L0804D26C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D27C @ =0x000021C5
    bl .L0804DA1A
    .align 2, 0
.L0804D27C: .word 0x000021C5
.L0804D280:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D298 @ =0x000021C5
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    bl .L0804DA28
    .align 2, 0
.L0804D298: .word 0x000021C5
.L0804D29C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D2BC @ =0x000021C6
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    bl .L0804DA2C
    .align 2, 0
.L0804D2BC: .word 0x000021C6
.L0804D2C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D2E0 @ =0x000021C6
    adds r1, r1, r2
    movs r0, #0xff
    ands r6, r0
    lsls r3, r6, #1
    ldrh r2, [r1]
    ldr r0, .L0804D2E4 @ =0xFFFFFE01
.L0804D2D6:
    ands r0, r2
    orrs r0, r3
    strh r0, [r1]
    bl .L0804DA2E
    .align 2, 0
.L0804D2E0: .word 0x000021C6
.L0804D2E4: .word 0xFFFFFE01
.L0804D2E8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D304 @ =0x000021C7
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #3
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D304: .word 0x000021C7
.L0804D308:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D324 @ =0x000021C7
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D324: .word 0x000021C7
.L0804D328:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D344 @ =0x000021C7
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D344: .word 0x000021C7
.L0804D348:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D364 @ =0x000021C7
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D364: .word 0x000021C7
.L0804D368:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D384 @ =0x000021C7
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D384: .word 0x000021C7
.L0804D388:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D394 @ =0x000021C7
    b .L0804DA1A
    .align 2, 0
.L0804D394: .word 0x000021C7
.L0804D398:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D3AC @ =0x000021C7
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    b .L0804DA28
    .align 2, 0
.L0804D3AC: .word 0x000021C7
.L0804D3B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D3CC @ =0x000021C8
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    b .L0804DA2C
    .align 2, 0
.L0804D3CC: .word 0x000021C8
.L0804D3D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D3EC @ =0x000021C8
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #3
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D3EC: .word 0x000021C8
.L0804D3F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D40C @ =0x000021AB
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D40C: .word 0x000021AB
.L0804D410:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D424 @ =0x000021AB
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    b .L0804DA28
    .align 2, 0
.L0804D424: .word 0x000021AB
.L0804D428:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D444 @ =0x000021AC
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    b .L0804DA2C
    .align 2, 0
.L0804D444: .word 0x000021AC
.L0804D448:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D464 @ =0x000021AC
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D464: .word 0x000021AC
.L0804D468:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D484 @ =0x000021AC
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D484: .word 0x000021AC
.L0804D488:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D49C @ =0x000021AC
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    b .L0804DA28
    .align 2, 0
.L0804D49C: .word 0x000021AC
.L0804D4A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D4BC @ =0x000021AD
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    b .L0804DA2C
    .align 2, 0
.L0804D4BC: .word 0x000021AD
.L0804D4C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D4DC @ =0x000021AD
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D4DC: .word 0x000021AD
.L0804D4E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D4FC @ =0x000021AD
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D4FC: .word 0x000021AD
.L0804D500:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D514 @ =0x000021AD
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    b .L0804DA28
    .align 2, 0
.L0804D514: .word 0x000021AD
.L0804D518:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D534 @ =0x000021AE
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    b .L0804DA2C
    .align 2, 0
.L0804D534: .word 0x000021AE
.L0804D538:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D554 @ =0x000021AE
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D554: .word 0x000021AE
.L0804D558:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D574 @ =0x000021AE
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D574: .word 0x000021AE
.L0804D578:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D58C @ =0x000021AE
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    b .L0804DA28
    .align 2, 0
.L0804D58C: .word 0x000021AE
.L0804D590:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D5AC @ =0x000021AF
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    b .L0804DA2C
    .align 2, 0
.L0804D5AC: .word 0x000021AF
.L0804D5B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D5CC @ =0x000021AF
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D5CC: .word 0x000021AF
.L0804D5D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D5EC @ =0x000021AF
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D5EC: .word 0x000021AF
.L0804D5F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D604 @ =0x000021AF
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    b .L0804DA28
    .align 2, 0
.L0804D604: .word 0x000021AF
.L0804D608:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D624 @ =0x000021B0
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    b .L0804DA2C
    .align 2, 0
.L0804D624: .word 0x000021B0
.L0804D628:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D644 @ =0x000021B0
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D644: .word 0x000021B0
.L0804D648:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D664 @ =0x000021B0
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D664: .word 0x000021B0
.L0804D668:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D67C @ =0x000021B0
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    b .L0804DA28
    .align 2, 0
.L0804D67C: .word 0x000021B0
.L0804D680:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D69C @ =0x000021B1
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    b .L0804DA2C
    .align 2, 0
.L0804D69C: .word 0x000021B1
.L0804D6A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D6BC @ =0x000021B1
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D6BC: .word 0x000021B1
.L0804D6C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D6DC @ =0x000021B1
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D6DC: .word 0x000021B1
.L0804D6E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D6F4 @ =0x000021B1
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    b .L0804DA28
    .align 2, 0
.L0804D6F4: .word 0x000021B1
.L0804D6F8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D714 @ =0x000021B2
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    b .L0804DA2C
    .align 2, 0
.L0804D714: .word 0x000021B2
.L0804D718:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D734 @ =0x000021B2
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D734: .word 0x000021B2
.L0804D738:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D754 @ =0x000021B2
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D754: .word 0x000021B2
.L0804D758:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D76C @ =0x000021B2
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    b .L0804DA28
    .align 2, 0
.L0804D76C: .word 0x000021B2
.L0804D770:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D78C @ =0x000021B3
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    b .L0804DA2C
    .align 2, 0
.L0804D78C: .word 0x000021B3
.L0804D790:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D7AC @ =0x000021B3
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D7AC: .word 0x000021B3
.L0804D7B0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D7CC @ =0x000021B3
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D7CC: .word 0x000021B3
.L0804D7D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D7E4 @ =0x000021B3
    adds r1, r1, r2
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    b .L0804DA28
    .align 2, 0
.L0804D7E4: .word 0x000021B3
.L0804D7E8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D804 @ =0x000021B4
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    b .L0804DA2C
    .align 2, 0
.L0804D804: .word 0x000021B4
.L0804D808:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D824 @ =0x000021B4
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D824: .word 0x000021B4
.L0804D828:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D844 @ =0x000021B4
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x31
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D844: .word 0x000021B4
.L0804D848:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D864 @ =0x000021C8
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D864: .word 0x000021C8
.L0804D868:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D884 @ =0x000021C8
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D884: .word 0x000021C8
.L0804D888:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D89C @ =0x000021C8
    adds r1, r1, r2
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0xf
    b .L0804DA28
    .align 2, 0
.L0804D89C: .word 0x000021C8
.L0804D8A0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D8BC @ =0x000021C9
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    b .L0804DA2C
    .align 2, 0
.L0804D8BC: .word 0x000021C9
.L0804D8C0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D8DC @ =0x000021C9
    adds r1, r1, r2
    movs r0, #0xf
    ands r6, r0
    lsls r3, r6, #1
    ldrb r2, [r1]
    movs r0, #0x1f
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D8DC: .word 0x000021C9
.L0804D8E0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D8FC @ =0x000021C9
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D8FC: .word 0x000021C9
.L0804D900:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D90C @ =0x000021C9
    b .L0804DA1A
    .align 2, 0
.L0804D90C: .word 0x000021C9
.L0804D910:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D924 @ =0x000021C9
    adds r1, r1, r2
    lsls r3, r6, #7
    ldrb r2, [r1]
    movs r0, #0x7f
    b .L0804DA28
    .align 2, 0
.L0804D924: .word 0x000021C9
.L0804D928:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D944 @ =0x000021CA
    adds r1, r1, r2
    movs r0, #3
    ands r6, r0
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r6
    b .L0804DA2C
    .align 2, 0
.L0804D944: .word 0x000021CA
.L0804D948:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D964 @ =0x000021CA
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #5
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D964: .word 0x000021CA
.L0804D968:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D984 @ =0x000021CA
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #3
    ldrb r2, [r1]
    movs r0, #9
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D984: .word 0x000021CA
.L0804D988:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D9A4 @ =0x000021CA
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #4
    ldrb r2, [r1]
    movs r0, #0x11
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D9A4: .word 0x000021CA
.L0804D9A8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D9C4 @ =0x000021CA
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804D9C4: .word 0x000021CA
.L0804D9C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D9D4 @ =0x000021CA
    b .L0804DA1A
    .align 2, 0
.L0804D9D4: .word 0x000021CA
.L0804D9D8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804D9EC @ =0x000021CB
    adds r1, r1, r2
    lsls r3, r6, #2
    ldrb r2, [r1]
    movs r0, #3
    b .L0804DA28
    .align 2, 0
.L0804D9EC: .word 0x000021CB
.L0804D9F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804DA0C @ =0x0000216E
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #5
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    b .L0804DA28
    .align 2, 0
.L0804DA0C: .word 0x0000216E
.L0804DA10:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0]
    ldr r2, .L0804DA50 @ =0x0000216E
.L0804DA1A:
    adds r1, r1, r2
    movs r0, #1
    ands r6, r0
    lsls r3, r6, #6
    ldrb r2, [r1]
    movs r0, #0x41
    rsbs r0, r0, #0
.L0804DA28:
    ands r0, r2
    orrs r0, r3
.L0804DA2C:
    strb r0, [r1]
.L0804DA2E:
    adds r0, r7, #0
    mov r1, r8
    bl VarGet__12ScriptEngineUi
    adds r2, r0, #0
    mov r1, r8
    subs r1, #0x46
    ldr r0, .L0804DA54
    cmp r1, r0
    bls .L0804DA44
    b .L0804E0E6
.L0804DA44:
    lsls r0, r1, #2
    ldr r1, .L0804DA58 @ =.LvariableWriteNotifications
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0804DA50: .word 0x0000216E
.L0804DA54: .word (.LvariableWriteNotificationsEnd - .LvariableWriteNotifications) / 4 - 1
.L0804DA58: .word .LvariableWriteNotifications
.LvariableWriteNotifications: @ jump table
    .word .L0804E08C @ case 0
    .word .L0804E08C @ case 1
    .word .L0804E0E6 @ case 2
    .word .L0804E08C @ case 3
    .word .L0804E08C @ case 4
    .word .L0804E08C @ case 5
    .word .L0804E08C @ case 6
    .word .L0804E08C @ case 7
    .word .L0804E08C @ case 8
    .word .L0804E08C @ case 9
    .word .L0804E08C @ case 10
    .word .L0804E0E6 @ case 11
    .word .L0804E08C @ case 12
    .word .L0804E0E6 @ case 13
    .word .L0804E08C @ case 14
    .word .L0804E08C @ case 15
    .word .L0804E08C @ case 16
    .word .L0804E08C @ case 17
    .word .L0804E08C @ case 18
    .word .L0804E0E6 @ case 19
    .word .L0804E08C @ case 20
    .word .L0804E0E6 @ case 21
    .word .L0804E08C @ case 22
    .word .L0804E0E6 @ case 23
    .word .L0804E08C @ case 24
    .word .L0804E08C @ case 25
    .word .L0804E08C @ case 26
    .word .L0804E08C @ case 27
    .word .L0804E08C @ case 28
    .word .L0804E0E6 @ case 29
    .word .L0804E08C @ case 30
    .word .L0804E08C @ case 31
    .word .L0804E08C @ case 32
    .word .L0804E08C @ case 33
    .word .L0804E08C @ case 34
    .word .L0804E08C @ case 35
    .word .L0804E08C @ case 36
    .word .L0804E08C @ case 37
    .word .L0804E0E6 @ case 38
    .word .L0804E08C @ case 39
    .word .L0804E08C @ case 40
    .word .L0804E08C @ case 41
    .word .L0804E08C @ case 42
    .word .L0804E08C @ case 43
    .word .L0804E08C @ case 44
    .word .L0804E08C @ case 45
    .word .L0804E08C @ case 46
    .word .L0804E08C @ case 47
    .word .L0804E08C @ case 48
    .word .L0804E08C @ case 49
    .word .L0804E0E6 @ case 50
    .word .L0804E0E6 @ case 51
    .word .L0804E08C @ case 52
    .word .L0804E08C @ case 53
    .word .L0804E08C @ case 54
    .word .L0804E08C @ case 55
    .word .L0804E08C @ case 56
    .word .L0804E08C @ case 57
    .word .L0804E0E6 @ case 58
    .word .L0804E0E6 @ case 59
    .word .L0804E08C @ case 60
    .word .L0804E08C @ case 61
    .word .L0804E08C @ case 62
    .word .L0804E08C @ case 63
    .word .L0804E08C @ case 64
    .word .L0804E08C @ case 65
    .word .L0804E0E6 @ case 66
    .word .L0804E0E6 @ case 67
    .word .L0804E08C @ case 68
    .word .L0804E08C @ case 69
    .word .L0804E08C @ case 70
    .word .L0804E08C @ case 71
    .word .L0804E08C @ case 72
    .word .L0804E08C @ case 73
    .word .L0804E0E6 @ case 74
    .word .L0804E0E6 @ case 75
    .word .L0804E08C @ case 76
    .word .L0804E08C @ case 77
    .word .L0804E08C @ case 78
    .word .L0804E08C @ case 79
    .word .L0804E08C @ case 80
    .word .L0804E08C @ case 81
    .word .L0804E0E6 @ case 82
    .word .L0804E0E6 @ case 83
    .word .L0804E08C @ case 84
    .word .L0804E08C @ case 85
    .word .L0804E08C @ case 86
    .word .L0804E08C @ case 87
    .word .L0804E08C @ case 88
    .word .L0804E08C @ case 89
    .word .L0804E08C @ case 90
    .word .L0804E08C @ case 91
    .word .L0804E08C @ case 92
    .word .L0804E08C @ case 93
    .word .L0804E08C @ case 94
    .word .L0804E08C @ case 95
    .word .L0804E08C @ case 96
    .word .L0804E08C @ case 97
    .word .L0804E08C @ case 98
    .word .L0804E08C @ case 99
    .word .L0804E08C @ case 100
    .word .L0804E08C @ case 101
    .word .L0804E08C @ case 102
    .word .L0804E08C @ case 103
    .word .L0804E08C @ case 104
    .word .L0804E08C @ case 105
    .word .L0804E08C @ case 106
    .word .L0804E08C @ case 107
    .word .L0804E08C @ case 108
    .word .L0804E08C @ case 109
    .word .L0804E08C @ case 110
    .word .L0804E08C @ case 111
    .word .L0804E08C @ case 112
    .word .L0804E08C @ case 113
    .word .L0804E08C @ case 114
    .word .L0804E08C @ case 115
    .word .L0804E08C @ case 116
    .word .L0804E08C @ case 117
    .word .L0804E08C @ case 118
    .word .L0804E08C @ case 119
    .word .L0804E08C @ case 120
    .word .L0804E08C @ case 121
    .word .L0804E08C @ case 122
    .word .L0804E08C @ case 123
    .word .L0804E08C @ case 124
    .word .L0804E08C @ case 125
    .word .L0804E08C @ case 126
    .word .L0804E08C @ case 127
    .word .L0804E08C @ case 128
    .word .L0804E08C @ case 129
    .word .L0804E08C @ case 130
    .word .L0804E08C @ case 131
    .word .L0804E08C @ case 132
    .word .L0804E08C @ case 133
    .word .L0804E08C @ case 134
    .word .L0804E08C @ case 135
    .word .L0804E08C @ case 136
    .word .L0804E08C @ case 137
    .word .L0804E08C @ case 138
    .word .L0804E08C @ case 139
    .word .L0804E0E6 @ case 140
    .word .L0804E0E6 @ case 141
    .word .L0804E0E6 @ case 142
    .word .L0804E0E6 @ case 143
    .word .L0804E0E6 @ case 144
    .word .L0804E08C @ case 145
    .word .L0804E08C @ case 146
    .word .L0804E08C @ case 147
    .word .L0804E08C @ case 148
    .word .L0804E08C @ case 149
    .word .L0804E08C @ case 150
    .word .L0804E08C @ case 151
    .word .L0804E0E6 @ case 152
    .word .L0804E08C @ case 153
    .word .L0804E08C @ case 154
    .word .L0804E08C @ case 155
    .word .L0804E08C @ case 156
    .word .L0804E08C @ case 157
    .word .L0804E08C @ case 158
    .word .L0804E0E6 @ case 159
    .word .L0804E08C @ case 160
    .word .L0804E08C @ case 161
    .word .L0804E08C @ case 162
    .word .L0804E08C @ case 163
    .word .L0804E08C @ case 164
    .word .L0804E08C @ case 165
    .word .L0804E08C @ case 166
    .word .L0804E08C @ case 167
    .word .L0804E08C @ case 168
    .word .L0804E08C @ case 169
    .word .L0804E08C @ case 170
    .word .L0804E08C @ case 171
    .word .L0804E08C @ case 172
    .word .L0804E08C @ case 173
    .word .L0804E0E6 @ case 174
    .word .L0804E0E6 @ case 175
    .word .L0804E0E6 @ case 176
    .word .L0804E0E6 @ case 177
    .word .L0804E0E6 @ case 178
    .word .L0804E08C @ case 179
    .word .L0804E08C @ case 180
    .word .L0804E08C @ case 181
    .word .L0804E08C @ case 182
    .word .L0804E08C @ case 183
    .word .L0804E0E6 @ case 184
    .word .L0804E08C @ case 185
    .word .L0804E08C @ case 186
    .word .L0804E0E6 @ case 187
    .word .L0804E08C @ case 188
    .word .L0804E0E6 @ case 189
    .word .L0804E08C @ case 190
    .word .L0804E08C @ case 191
    .word .L0804E08C @ case 192
    .word .L0804E08C @ case 193
    .word .L0804E0E6 @ case 194
    .word .L0804E0E6 @ case 195
    .word .L0804E08C @ case 196
    .word .L0804E08C @ case 197
    .word .L0804E0E6 @ case 198
    .word .L0804E0E6 @ case 199
    .word .L0804E08C @ case 200
    .word .L0804E08C @ case 201
    .word .L0804E08C @ case 202
    .word .L0804E08C @ case 203
    .word .L0804E08C @ case 204
    .word .L0804E0E6 @ case 205: variable 275 has no post-write side effect
    .word .L0804E08C @ case 206
    .word .L0804E08C @ case 207
    .word .L0804E08C @ case 208
    .word .L0804E08C @ case 209
    .word .L0804E08C @ case 210
    .word .L0804E08C @ case 211
    .word .L0804E08C @ case 212
    .word .L0804E08C @ case 213
    .word .L0804E08C @ case 214
    .word .L0804E08C @ case 215
    .word .L0804E08C @ case 216
    .word .L0804E08C @ case 217
    .word .L0804E08C @ case 218
    .word .L0804E08C @ case 219
    .word .L0804E08C @ case 220
    .word .L0804E08C @ case 221
    .word .L0804E0E6 @ case 222
    .word .L0804E0E6 @ case 223
    .word .L0804E08C @ case 224
    .word .L0804E08C @ case 225
    .word .L0804E08C @ case 226
    .word .L0804E0E6 @ case 227
    .word .L0804E08C @ case 228
    .word .L0804E08C @ case 229
    .word .L0804E08C @ case 230
    .word .L0804E08C @ case 231
    .word .L0804E08C @ case 232
    .word .L0804E08C @ case 233
    .word .L0804E08C @ case 234
    .word .L0804E0E6 @ case 235
    .word .L0804E08C @ case 236
    .word .L0804E08C @ case 237
    .word .L0804E08C @ case 238
    .word .L0804E08C @ case 239
    .word .L0804E08C @ case 240
    .word .L0804E08C @ case 241
    .word .L0804E08C @ case 242
    .word .L0804E08C @ case 243
    .word .L0804E0E6 @ case 244
    .word .L0804E08C @ case 245
    .word .L0804E08C @ case 246
    .word .L0804E08C @ case 247
    .word .L0804E08C @ case 248
    .word .L0804E08C @ case 249
    .word .L0804E08C @ case 250
    .word .L0804E08C @ case 251
    .word .L0804E08C @ case 252
    .word .L0804E08C @ case 253
    .word .L0804E0E6 @ case 254
    .word .L0804E08C @ case 255
    .word .L0804E08C @ case 256
    .word .L0804E0E6 @ case 257
    .word .L0804E08C @ case 258
    .word .L0804E08C @ case 259
    .word .L0804E08C @ case 260
    .word .L0804E08C @ case 261
    .word .L0804E08C @ case 262
    .word .L0804E0E6 @ case 263
    .word .L0804E08C @ case 264
    .word .L0804E08C @ case 265
    .word .L0804E08C @ case 266
    .word .L0804E08C @ case 267
    .word .L0804E08C @ case 268
    .word .L0804E08C @ case 269
    .word .L0804E0E6 @ case 270
    .word .L0804E08C @ case 271
    .word .L0804E08C @ case 272
    .word .L0804E0E6 @ case 273
    .word .L0804E08C @ case 274
    .word .L0804E08C @ case 275
    .word .L0804E08C @ case 276
    .word .L0804E08C @ case 277
    .word .L0804E08C @ case 278
    .word .L0804E08C @ case 279
    .word .L0804E08C @ case 280
    .word .L0804E08C @ case 281
    .word .L0804E08C @ case 282
    .word .L0804E08C @ case 283
    .word .L0804E08C @ case 284
    .word .L0804E08C @ case 285
    .word .L0804E08C @ case 286
    .word .L0804E08C @ case 287
    .word .L0804E08C @ case 288
    .word .L0804E08C @ case 289
    .word .L0804E08C @ case 290
    .word .L0804E08C @ case 291
    .word .L0804E08C @ case 292
    .word .L0804E08C @ case 293
    .word .L0804E08C @ case 294
    .word .L0804E08C @ case 295
    .word .L0804E08C @ case 296
    .word .L0804E08C @ case 297
    .word .L0804E08C @ case 298
    .word .L0804E08C @ case 299
    .word .L0804E08C @ case 300
    .word .L0804E08C @ case 301
    .word .L0804E08C @ case 302
    .word .L0804E08C @ case 303
    .word .L0804E08C @ case 304
    .word .L0804E08C @ case 305
    .word .L0804E08C @ case 306
    .word .L0804E08C @ case 307
    .word .L0804E08C @ case 308
    .word .L0804E08C @ case 309
    .word .L0804E08C @ case 310
    .word .L0804E08C @ case 311
    .word .L0804E08C @ case 312
    .word .L0804E08C @ case 313
    .word .L0804E08C @ case 314
    .word .L0804E08C @ case 315
    .word .L0804E0E6 @ case 316
    .word .L0804E0E6 @ case 317
    .word .L0804E0E6 @ case 318
    .word .L0804E0E6 @ case 319
    .word .L0804E0E6 @ case 320
    .word .L0804E08C @ case 321
    .word .L0804E0E6 @ case 322
    .word .L0804E08C @ case 323
    .word .L0804E0E6 @ case 324
    .word .L0804E08C @ case 325
    .word .L0804E08C @ case 326
    .word .L0804E0E6 @ case 327
    .word .L0804E08C @ case 328
    .word .L0804E0E6 @ case 329
    .word .L0804E0E6 @ case 330
    .word .L0804E0E6 @ case 331
    .word .L0804E08C @ case 332
    .word .L0804E0E6 @ case 333
    .word .L0804E08C @ case 334
    .word .L0804E0E6 @ case 335
    .word .L0804E08C @ case 336
    .word .L0804E0E6 @ case 337
    .word .L0804E08C @ case 338
    .word .L0804E0E6 @ case 339
    .word .L0804E08C @ case 340
    .word .L0804E0E6 @ case 341
    .word .L0804E08C @ case 342
    .word .L0804E0E6 @ case 343
    .word .L0804E08C @ case 344
    .word .L0804E0E6 @ case 345
    .word .L0804E08C @ case 346
    .word .L0804E0E6 @ case 347
    .word .L0804E08C @ case 348
    .word .L0804E08C @ case 349
    .word .L0804E08C @ case 350
    .word .L0804E0E6 @ case 351
    .word .L0804E0E6 @ case 352
    .word .L0804E0E6 @ case 353: variable 423 has no post-write side effect
    .word .L0804E08C @ case 354
    .word .L0804E0E6 @ case 355
    .word .L0804E08C @ case 356
    .word .L0804E0E6 @ case 357
    .word .L0804E08C @ case 358
    .word .L0804E0E6 @ case 359
    .word .L0804E08C @ case 360
    .word .L0804E0E6 @ case 361
    .word .L0804E08C @ case 362
    .word .L0804E0E6 @ case 363
    .word .L0804E08C @ case 364
    .word .L0804E08C @ case 365
    .word .L0804E08C @ case 366
    .word .L0804E08C @ case 367
    .word .L0804E08C @ case 368
    .word .L0804E0E6 @ case 369
    .word .L0804E08C @ case 370
    .word .L0804E0E6 @ case 371
    .word .L0804E08C @ case 372
    .word .L0804E0E6 @ case 373
    .word .L0804E08C @ case 374
    .word .L0804E0E6 @ case 375
    .word .L0804E08C @ case 376
    .word .L0804E0E6 @ case 377
    .word .L0804E08C @ case 378
    .word .L0804E08C @ case 379
    .word .L0804E0E6 @ case 380
    .word .L0804E0E6 @ case 381
    .word .L0804E0E6 @ case 382
    .word .L0804E0E6 @ case 383
    .word .L0804E0E6 @ case 384
    .word .L0804E0E6 @ case 385
    .word .L0804E08C @ case 386
    .word .L0804E08C @ case 387
    .word .L0804E08C @ case 388
    .word .L0804E08C @ case 389
    .word .L0804E08C @ case 390
    .word .L0804E08C @ case 391
    .word .L0804E08C @ case 392
    .word .L0804E0E6 @ case 393
    .word .L0804E08C @ case 394
    .word .L0804E08C @ case 395
.LvariableWriteNotificationsEnd:
.L0804E08C:
    cmp r2, sb
    beq .L0804E0E6
    cmp r2, #1
    beq .L0804E0A4
    cmp r2, #1
    bgt .L0804E09E
    cmp r2, #0
    beq .L0804E0D0
    b .L0804E0E6
.L0804E09E:
    cmp r2, #2
    beq .L0804E0D0
    b .L0804E0E6
.L0804E0A4:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .L0804E0B4
    bl TalkResetUi__9GameScene
.L0804E0B4:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r7, r2
    ldr r0, [r0]
    ldr r1, .L0804E0CC @ =0x0000214C
    adds r0, r0, r1
    mov r2, r8
    lsls r1, r2, #0x10
    lsrs r1, r1, #0x10
    bl RegisterEventVariable__14GameEventStateUs
    b .L0804E0E6
    .align 2, 0
.L0804E0CC: .word 0x0000214C
.L0804E0D0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r0, [r0]
    ldr r2, .L0804E0F4 @ =0x0000214C
    adds r0, r0, r2
    mov r2, r8
    lsls r1, r2, #0x10
    lsrs r1, r1, #0x10
    bl RemoveEventVariable__14GameEventStateUs
.L0804E0E6:
    add sp, #8
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0804E0F4: .word 0x0000214C
