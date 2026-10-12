#ifndef MONEY_ACCOUNT_HH
#define MONEY_ACCOUNT_HH

#include "prelude.h"

struct MoneyAccountRecord {
    u32 income;
    u32 expense;
};

// The native account has two bounded record histories. Their capacities and
// income/expense fields are verified, but their time periods are not yet named.
template <unsigned Capacity>
struct MoneyAccountHistory {
    u32 count;
    MoneyAccountRecord records[Capacity];

    // Index zero selects the newest record. Out-of-range indices select the
    // first slot, exactly as in the original readers (including an empty list).
    MoneyAccountRecord const * GetRecord(u32 index) const
    {
        if (index >= count)
            return records;
        return records + (count - (index + 1));
    }
};

struct MoneyAccount {
    u32 balance;
    u8 unk_04_0 : 1;
    u8 unk_04_1 : 1;
    u8 unk_04_2 : 6;
    u8 unk_05[3];
    MoneyAccountHistory<30> history_08;
    MoneyAccountHistory<4> history_FC;
    u32 max_income_08;
    u32 max_expense_08;
    u32 max_income_FC;
    u32 max_expense_FC;
};

typedef char MoneyAccountRecordSizeCheck[sizeof(MoneyAccountRecord) == 8 ? 1 : -1];
typedef char MoneyAccountSizeCheck[sizeof(MoneyAccount) == 0x130 ? 1 : -1];
typedef char MoneyAccountHistory08Check[offsetof(MoneyAccount, history_08) == 8 ? 1 : -1];
typedef char MoneyAccountHistoryFCCheck[offsetof(MoneyAccount, history_FC) == 0xFC ? 1 : -1];
typedef char MoneyAccountMaximaCheck[offsetof(MoneyAccount, max_income_08) == 0x120 ? 1 : -1];

EXTERN_C

MoneyAccount * InitializeMoneyAccount(MoneyAccount * account) SECTION(".text.money_account_init");
MoneyAccountRecord const * GetMoneyAccountRecord30(MoneyAccount const * account, u32 index);
MoneyAccountRecord const * GetMoneyAccountRecord4(MoneyAccount const * account, u32 index);

// Still implemented by the original assembly: update the recorded maxima,
// append a zero record to history_FC and reset history_08 to one zero record.
void UpdateMoneyAccountRecordHistory(MoneyAccount * account);

EXTERN_C_END

#endif // MONEY_ACCOUNT_HH
