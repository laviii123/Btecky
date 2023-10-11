// Define a class for bank accounts
class BankAccount {
  constructor(accountNumber, accountHolder, balance = 0) {
    this.accountNumber = accountNumber;
    this.accountHolder = accountHolder;
    this.balance = balance;
  }

  deposit(amount) {
    this.balance += amount;
    console.log(`Deposited $${amount} into account ${this.accountNumber}. New balance: $${this.balance}`);
  }

  withdraw(amount) {
    if (this.balance >= amount) {
      this.balance -= amount;
      console.log(`Withdrawn $${amount} from account ${this.accountNumber}. New balance: $${this.balance}`);
    } else {
      console.log(`Insufficient funds in account ${this.accountNumber}.`);
    }
  }

  getBalance() {
    console.log(`Account ${this.accountNumber} balance: $${this.balance}`);
  }
}

// Create some bank accounts
const account1 = new BankAccount(1, "Alice", 1000);
const account2 = new BankAccount(2, "Bob", 500);

// Perform transactions
account1.getBalance();
account1.deposit(500);
account1.withdraw(200);
account1.getBalance();

account2.getBalance();
account2.deposit(1000);
account2.withdraw(800);
account2.getBalance();
