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
    account->max_income_08 = 0;
    account->max_expense_08 = 0;
    account->max_income_FC = 0;
    account->max_expense_FC = 0;
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
        u32 maximum = account->max_income_08;
        u32 current = account->history_08.Last().income;
        if (maximum < current)
            account->max_income_08 = current;
        maximum = account->max_expense_08;
        current = account->history_08.Last().expense;
        if (maximum < current)
            account->max_expense_08 = current;
    }
    while (account->history_08.Size() >= 30)
        account->history_08.Erase(account->history_08.Begin());
    account->history_08.Append(MoneyAccountRecord());
}

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
    u32 const & maximum = account->max_income_08;
    u32 const & result = maximum < current ? current : maximum;
    return result;
}

u32 GetMoneyAccountMaximumExpense30(MoneyAccount const * account)
{
    u32 const & current = account->history_08.Last().expense;
    u32 const & maximum = account->max_expense_08;
    u32 const & result = maximum < current ? current : maximum;
    return result;
}

u32 GetMoneyAccountMaximumIncome4(MoneyAccount const * account)
{
    u32 const & current = account->history_FC.Last().income;
    u32 const & maximum = account->max_income_FC;
    u32 const & result = maximum < current ? current : maximum;
    return result;
}

u32 GetMoneyAccountMaximumExpense4(MoneyAccount const * account)
{
    u32 const & current = account->history_FC.Last().expense;
    u32 const & maximum = account->max_expense_FC;
    u32 const & result = maximum < current ? current : maximum;
    return result;
}
