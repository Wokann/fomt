#include "money_account.hh"

template <typename T>
inline T LimitedAmount(T available, T amount)
{
    return amount < available ? amount : available;
}

MoneyAccount * InitializeMoneyAccount(MoneyAccount * account)
{
    account->balance = 500;
    account->unk_04_0 = 0;
    account->unk_04_1 = 0;
    account->history_08.count = 0;
    account->history_FC.count = 0;
    account->maximum_08.income = 0;
    account->maximum_08.expense = 0;
    account->maximum_FC.income = 0;
    account->maximum_FC.expense = 0;
    UpdateMoneyAccountRecordHistory(account);
    return account;
}

void AddMoneyToAccount(MoneyAccount * account, u32 amount)
{
    if (account->history_FC.Empty())
        account->history_FC.Append(MoneyAccountRecord());
    if (account->history_08.Empty())
        account->history_08.Append(MoneyAccountRecord());

    u32 old_balance = account->GetBalance();
    account->balance = old_balance + LimitedAmount(1000000000u - old_balance, amount);
    if (account->balance > 99999999)
        account->unk_04_1 = 1;

    MoneyAccountRecord & record30 = account->history_08.Last();
    MoneyAccountRecord & record4 = account->history_FC.Last();
    record30.income += LimitedAmount(1000000000u - record30.income, amount);
    record4.income += LimitedAmount(1000000000u - record4.income, amount);
    if (record30.income > 99999)
        account->unk_04_0 = 1;
}

bool SubtractMoneyFromAccount(MoneyAccount * account, u32 amount)
{
    // Native callers also get an empty record when a purchase is rejected.
    if (account->history_FC.Empty())
        account->history_FC.Append(MoneyAccountRecord());
    if (account->history_08.Empty())
        account->history_08.Append(MoneyAccountRecord());

    if (amount > account->balance)
        return false;
    account->balance -= LimitedAmount(account->balance, amount);

    MoneyAccountRecord & record30 = account->history_08.Last();
    MoneyAccountRecord & record4 = account->history_FC.Last();
    record30.expense += LimitedAmount(1000000000u - record30.expense, amount);
    record4.expense += LimitedAmount(1000000000u - record4.expense, amount);
    if (record30.expense > 99999)
        account->unk_04_0 = 1;
    return true;
}

void AppendMoneyAccountRecord30(MoneyAccount * account)
{
    if (!account->history_08.Empty()) {
        u32 maximum = account->maximum_08.income;
        u32 current = account->history_08.Last().income;
        if (maximum < current)
            account->maximum_08.income = current;
        maximum = account->maximum_08.expense;
        current = account->history_08.Last().expense;
        if (maximum < current)
            account->maximum_08.expense = current;
    }
    while (account->history_08.Size() >= 30)
        account->history_08.Erase(account->history_08.Begin());
    account->history_08.Append(MoneyAccountRecord());
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "thumb_func_start UpdateMoneyAccountRecordHistory\n"
    "UpdateMoneyAccountRecordHistory:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, sl\n"
    "    mov r6, r9\n"
    "    mov r5, r8\n"
    "    push {r5, r6, r7}\n"
    "    sub sp, #16\n"
    "    mov ip, r0\n"
    "    mov r3, ip\n"
    "    adds r3, #8\n"
    "    movs r1, #0\n"
    "    mov r2, ip\n"
    "    ldr r0, [r2, #8]\n"
    "    cmp r0, #0\n"
    "    bne .Lscalar_4_0\n"
    "    movs r1, #1\n"
    ".Lscalar_4_0:\n"
    "    cmp r1, #0\n"
    "    bne .Lscalar_4_2\n"
    "    movs r2, #144\n"
    "    lsls r2, r2, #1\n"
    "    add r2, ip\n"
    "    ldr r1, [r2, #0]\n"
    "    subs r0, #1\n"
    "    lsls r0, r0, #3\n"
    "    adds r0, #4\n"
    "    adds r0, r3, r0\n"
    "    ldr r0, [r0, #0]\n"
    "    cmp r1, r0\n"
    "    bcs .Lscalar_4_1\n"
    "    str r0, [r2, #0]\n"
    ".Lscalar_4_1:\n"
    "    movs r2, #146\n"
    "    lsls r2, r2, #1\n"
    "    add r2, ip\n"
    "    ldr r1, [r2, #0]\n"
    "    mov r4, ip\n"
    "    ldr r0, [r4, #8]\n"
    "    subs r0, #1\n"
    "    lsls r0, r0, #3\n"
    "    adds r0, #4\n"
    "    adds r0, r3, r0\n"
    "    ldr r0, [r0, #4]\n"
    "    cmp r1, r0\n"
    "    bcs .Lscalar_4_2\n"
    "    str r0, [r2, #0]\n"
    ".Lscalar_4_2:\n"
    "    mov r0, ip\n"
    "    adds r0, #252\n"
    "    movs r1, #0\n"
    "    ldr r3, [r0, #0]\n"
    "    adds r6, r0, #0\n"
    "    cmp r3, #0\n"
    "    bne .Lscalar_4_3\n"
    "    movs r1, #1\n"
    ".Lscalar_4_3:\n"
    "    cmp r1, #0\n"
    "    bne .Lscalar_4_5\n"
    "    movs r2, #148\n"
    "    lsls r2, r2, #1\n"
    "    add r2, ip\n"
    "    ldr r1, [r2, #0]\n"
    "    subs r0, r3, #1\n"
    "    lsls r0, r0, #3\n"
    "    adds r0, #4\n"
    "    adds r0, r6, r0\n"
    "    ldr r0, [r0, #0]\n"
    "    cmp r1, r0\n"
    "    bcs .Lscalar_4_4\n"
    "    str r0, [r2, #0]\n"
    ".Lscalar_4_4:\n"
    "    movs r2, #150\n"
    "    lsls r2, r2, #1\n"
    "    add r2, ip\n"
    "    ldr r1, [r2, #0]\n"
    "    ldr r0, [r6, #0]\n"
    "    subs r0, #1\n"
    "    lsls r0, r0, #3\n"
    "    adds r0, #4\n"
    "    adds r0, r6, r0\n"
    "    ldr r0, [r0, #4]\n"
    "    cmp r1, r0\n"
    "    bcs .Lscalar_4_5\n"
    "    str r0, [r2, #0]\n"
    ".Lscalar_4_5:\n"
    "    ldr r0, [r6, #0]\n"
    "    movs r1, #8\n"
    "    add r1, ip\n"
    "    mov sl, r1\n"
    "    add r2, sp, #8\n"
    "    mov r9, r2\n"
    "    movs r4, #12\n"
    "    add r4, ip\n"
    "    mov r8, r4\n"
    "    cmp r0, #3\n"
    "    bls .Lscalar_4_10\n"
    "    adds r4, r6, #0\n"
    "    movs r7, #128\n"
    "    lsls r7, r7, #1\n"
    "    add r7, ip\n"
    ".Lscalar_4_6:\n"
    "    ldr r0, [r4, #0]\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_4_9\n"
    "    lsls r0, r0, #3\n"
    "    adds r0, #4\n"
    "    adds r0, r6, r0\n"
    "    movs r1, #132\n"
    "    lsls r1, r1, #1\n"
    "    add r1, ip\n"
    "    cmp r1, r0\n"
    "    beq .Lscalar_4_8\n"
    "    adds r3, r1, #0\n"
    "    adds r5, r7, #0\n"
    "    subs r0, r0, r3\n"
    "    asrs r2, r0, #3\n"
    "    cmp r2, #0\n"
    "    ble .Lscalar_4_8\n"
    ".Lscalar_4_7:\n"
    "    ldmia r3!, {r0, r1}\n"
    "    stmia r5!, {r0, r1}\n"
    "    subs r2, #1\n"
    "    cmp r2, #0\n"
    "    bgt .Lscalar_4_7\n"
    ".Lscalar_4_8:\n"
    "    ldr r0, [r4, #0]\n"
    "    subs r0, #1\n"
    "    str r0, [r4, #0]\n"
    ".Lscalar_4_9:\n"
    "    ldr r0, [r4, #0]\n"
    "    cmp r0, #3\n"
    "    bhi .Lscalar_4_6\n"
    ".Lscalar_4_10:\n"
    "    movs r0, #0\n"
    "    str r0, [sp, #0]\n"
    "    str r0, [sp, #4]\n"
    "    adds r1, r6, #0\n"
    "    ldr r0, [r1, #0]\n"
    "    cmp r0, #3\n"
    "    bhi .Lscalar_4_12\n"
    "    lsls r0, r0, #3\n"
    "    adds r0, #4\n"
    "    adds r2, r1, r0\n"
    "    cmp r2, #0\n"
    "    beq .Lscalar_4_11\n"
    "    ldr r0, [sp, #0]\n"
    "    ldr r1, [sp, #4]\n"
    "    str r0, [r2, #0]\n"
    "    str r1, [r2, #4]\n"
    ".Lscalar_4_11:\n"
    "    ldr r0, [r6, #0]\n"
    "    adds r0, #1\n"
    "    str r0, [r6, #0]\n"
    ".Lscalar_4_12:\n"
    "    mov r1, r9\n"
    "    movs r0, #0\n"
    "    str r0, [sp, #8]\n"
    "    str r0, [r1, #4]\n"
    "    mov r4, sl\n"
    "    movs r5, #1\n"
    "    adds r6, r1, #0\n"
    "    mov r1, ip\n"
    "    ldr r0, [r1, #8]\n"
    "    cmp r5, r0\n"
    "    bls .Lscalar_4_18\n"
    "    lsls r0, r0, #3\n"
    "    adds r0, #4\n"
    "    mov r1, r8\n"
    "    adds r0, r4, r0\n"
    "    cmp r1, r0\n"
    "    beq .Lscalar_4_14\n"
    "    ldr r2, [sp, #8]\n"
    "    ldr r3, [sp, #12]\n"
    ".Lscalar_4_13:\n"
    "    stmia r1!, {r2, r3}\n"
    "    cmp r1, r0\n"
    "    bne .Lscalar_4_13\n"
    ".Lscalar_4_14:\n"
    "    ldr r1, [r4, #0]\n"
    "    lsls r0, r1, #3\n"
    "    adds r0, #4\n"
    "    subs r3, r5, r1\n"
    "    adds r2, r4, r0\n"
    "    cmp r3, #0\n"
    "    beq .Lscalar_4_17\n"
    ".Lscalar_4_15:\n"
    "    cmp r2, #0\n"
    "    beq .Lscalar_4_16\n"
    "    ldr r0, [r6, #0]\n"
    "    ldr r1, [r6, #4]\n"
    "    str r0, [r2, #0]\n"
    "    str r1, [r2, #4]\n"
    ".Lscalar_4_16:\n"
    "    subs r3, #1\n"
    "    adds r2, #8\n"
    "    cmp r3, #0\n"
    "    bne .Lscalar_4_15\n"
    ".Lscalar_4_17:\n"
    "    str r5, [r4, #0]\n"
    "    b .Lscalar_4_22\n"
    ".Lscalar_4_18:\n"
    "    mov r3, r8\n"
    "    movs r2, #1\n"
    "    ldr r0, [sp, #8]\n"
    "    ldr r1, [sp, #12]\n"
    ".Lscalar_4_19:\n"
    "    stmia r3!, {r0, r1}\n"
    "    subs r2, #1\n"
    "    cmp r2, #0\n"
    "    bne .Lscalar_4_19\n"
    "    adds r5, r3, #0\n"
    "    ldr r0, [r4, #0]\n"
    "    lsls r0, r0, #3\n"
    "    adds r0, #4\n"
    "    adds r0, r4, r0\n"
    "    adds r2, r0, #0\n"
    "    adds r1, r5, #0\n"
    "    ldr r3, [r4, #0]\n"
    "    cmp r1, r2\n"
    "    beq .Lscalar_4_21\n"
    ".Lscalar_4_20:\n"
    "    adds r1, #8\n"
    "    cmp r1, r2\n"
    "    bne .Lscalar_4_20\n"
    ".Lscalar_4_21:\n"
    "    subs r0, r0, r5\n"
    "    asrs r0, r0, #3\n"
    "    subs r0, r3, r0\n"
    "    str r0, [r4, #0]\n"
    ".Lscalar_4_22:\n"
    "    add sp, #16\n"
    "    pop {r3, r4, r5}\n"
    "    mov r8, r3\n"
    "    mov r9, r4\n"
    "    mov sl, r5\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r0}\n"
    "    bx r0\n"
);

MoneyAccountRecord const * GetMoneyAccountRecord30(MoneyAccount const * account, u32 index)
{
    return account->history_08.GetRecord(index);
}

MoneyAccountRecord const * GetMoneyAccountRecord4(MoneyAccount const * account, u32 index)
{
    return account->history_FC.GetRecord(index);
}

u32 GetMoneyAccountMaximumIncome30(MoneyAccount const * account)
{
    u32 const & current = account->history_08.Last().income;
    u32 const & maximum = account->maximum_08.income;
    u32 const & result = maximum < current ? current : maximum;
    return result;
}

u32 GetMoneyAccountMaximumExpense30(MoneyAccount const * account)
{
    u32 const & current = account->history_08.Last().expense;
    u32 const & maximum = account->maximum_08.expense;
    u32 const & result = maximum < current ? current : maximum;
    return result;
}

u32 GetMoneyAccountMaximumIncome4(MoneyAccount const * account)
{
    u32 const & current = account->history_FC.Last().income;
    u32 const & maximum = account->maximum_FC.income;
    u32 const & result = maximum < current ? current : maximum;
    return result;
}

u32 GetMoneyAccountMaximumExpense4(MoneyAccount const * account)
{
    u32 const & current = account->history_FC.Last().expense;
    u32 const & maximum = account->maximum_FC.expense;
    u32 const & result = maximum < current ? current : maximum;
    return result;
}
