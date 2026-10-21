#ifndef MONEY_ACCOUNT_HH
#define MONEY_ACCOUNT_HH

#include "prelude.h"

struct MoneyAccountRecord {
    u32 income;
    u32 expense;

    MoneyAccountRecord(u32 income = 0, u32 expense = 0)
        : income(income), expense(expense) {}

    static void * operator new(size_t, void * storage) throw() { return storage; }
};

// The native account has two bounded record histories. Their capacities and
// income/expense fields are verified, but their time periods are not yet named.
template <unsigned Capacity>
struct MoneyAccountHistory {
    // The owning initializer sets count; default construction preserves storage.
    MoneyAccountHistory() {}
    MoneyAccountHistory(MoneyAccountHistory const & other) : count(0)
    {
        u32 active = other.count;
        MoneyAccountRecord const * start = other.Begin();
        // The record arena is word storage; derive its byte extent from the type.
        u32 end_address = active * sizeof(MoneyAccountRecord);
        end_address += reinterpret_cast<u32>(start);
        MoneyAccountRecord const * last = reinterpret_cast<MoneyAccountRecord const *>(end_address);
        MoneyAccountRecord const * first = other.Begin();
        MoneyAccountRecord * destination = Begin();
        while (first != last) {
            new (destination) MoneyAccountRecord(*first);
            ++first;
            ++destination;
        }
        count = active;
    }

    // End only the active record lifetimes; do not clear or reset storage.
    ~MoneyAccountHistory()
    {
        MoneyAccountRecord * last = End();
        MoneyAccountRecord * first = Begin();
        while (first != last) {
            first->~MoneyAccountRecord();
            ++first;
        }
    }

    u32 count;
    // Slots are constructed only when appended. Default-constructing a full
    // record array would incorrectly clear the unused native save storage.
    u32 storage[sizeof(MoneyAccountRecord) * Capacity / sizeof(u32)];

    u32 Size() const { return count; }
    bool Empty() const { return count == 0; }
    MoneyAccountRecord * Begin() { return reinterpret_cast<MoneyAccountRecord *>(storage); }
    MoneyAccountRecord const * Begin() const { return reinterpret_cast<MoneyAccountRecord const *>(storage); }
    MoneyAccountRecord * End() { return &(*this)[count]; }

    void Append(MoneyAccountRecord const & value)
    {
        if (Size() < Capacity) {
            new (End()) MoneyAccountRecord(value);
            ++count;
        }
    }

    void Erase(MoneyAccountRecord * position)
    {
        if (count != 0) {
            MoneyAccountRecord * last = End();
            MoneyAccountRecord * next = position + 1;
            if (next != last) {
                MoneyAccountRecord * source = next;
                MoneyAccountRecord * destination = position;
                for (ptrdiff_t remaining = last - source; remaining > 0; --remaining) {
                    *destination = *source;
                    ++destination;
                    ++source;
                }
            }
            --count;
        }
    }

    // Index zero selects the newest record. Out-of-range indices select the
    // first slot, exactly as in the original readers (including an empty list).
    MoneyAccountRecord const * GetRecord(u32 index) const
    {
        if (index >= count)
            return reinterpret_cast<MoneyAccountRecord const *>(storage);
        return reinterpret_cast<MoneyAccountRecord const *>(storage) + (count - (index + 1));
    }

    // The original maximum readers require a nonempty history. Initialization
    // and the record update routines establish that invariant.
    MoneyAccountRecord const & Last() const
    {
        return (*this)[count - 1];
    }

    MoneyAccountRecord & Last()
    {
        return (*this)[count - 1];
    }

    MoneyAccountRecord & operator[](u32 index)
    {
        return reinterpret_cast<MoneyAccountRecord *>(storage)[index];
    }

    MoneyAccountRecord const & operator[](u32 index) const
    {
        return reinterpret_cast<MoneyAccountRecord const *>(storage)[index];
    }
};

// Each native maximum is one income/expense pair, copied as an eight-byte value.
// Plain default initialization leaves it for InitializeMoneyAccount to fill.
struct MoneyAccountMaximumRecord {
    u32 income;
    u32 expense;
};

struct MoneyAccount {
    MoneyAccount();
    MoneyAccount(MoneyAccount const & other);
    ~MoneyAccount();

    u32 balance;
    u8 unk_04_0 : 1;
    u8 unk_04_1 : 1;
    u8 unk_04_2 : 6;
    u8 unk_05[3];
    MoneyAccountHistory<30> history_08;
    MoneyAccountHistory<4> history_FC;
    MoneyAccountMaximumRecord maximum_08;
    MoneyAccountMaximumRecord maximum_FC;

    u32 GetBalance() const { return balance; }
};

typedef char MoneyAccountMaximumRecordSizeCheck[sizeof(MoneyAccountMaximumRecord) == 8 ? 1 : -1];

typedef char MoneyAccountRecordSizeCheck[sizeof(MoneyAccountRecord) == 8 ? 1 : -1];
typedef char MoneyAccountSizeCheck[sizeof(MoneyAccount) == 0x130 ? 1 : -1];
typedef char MoneyAccountHistory08Check[offsetof(MoneyAccount, history_08) == 8 ? 1 : -1];
typedef char MoneyAccountHistoryFCCheck[offsetof(MoneyAccount, history_FC) == 0xFC ? 1 : -1];
typedef char MoneyAccountMaximaCheck[offsetof(MoneyAccount, maximum_08) == 0x120 ? 1 : -1];

typedef char MoneyAccountMaximumFCCheck[offsetof(MoneyAccount, maximum_FC) == 0x128 ? 1 : -1];

EXTERN_C

MoneyAccount * InitializeMoneyAccount(MoneyAccount * account) SECTION(".text.money_account_update");
void AddMoneyToAccount(MoneyAccount * account, u32 amount) SECTION(".text.money_account_update");
bool SubtractMoneyFromAccount(MoneyAccount * account, u32 amount) SECTION(".text.money_account_update");
void AppendMoneyAccountRecord30(MoneyAccount * account) SECTION(".text.money_account_update");
MoneyAccountRecord const * GetMoneyAccountRecord30(MoneyAccount const * account, u32 index);
MoneyAccountRecord const * GetMoneyAccountRecord4(MoneyAccount const * account, u32 index);
u32 GetMoneyAccountMaximumIncome30(MoneyAccount const * account);
u32 GetMoneyAccountMaximumExpense30(MoneyAccount const * account);
u32 GetMoneyAccountMaximumIncome4(MoneyAccount const * account);
u32 GetMoneyAccountMaximumExpense4(MoneyAccount const * account);

// Still implemented by the original assembly: update the recorded maxima,
// append a zero record to history_FC and reset history_08 to one zero record.
void UpdateMoneyAccountRecordHistory(MoneyAccount * account);

EXTERN_C_END

inline MoneyAccount::MoneyAccount() { InitializeMoneyAccount(this); }

#endif // MONEY_ACCOUNT_HH
