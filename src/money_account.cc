#include "money_account.hh"

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
