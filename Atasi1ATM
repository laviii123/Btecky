import java.util.Scanner;
class Account
{
    String name;
    String userName;
    String password;
    int accountNo;
    float balance=100000f;
    int transactions=0;
    String transactionHistroy="";

    public void Register()
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("\nEnter Your Name: ");
        this.name=sc.nextLine();
        System.out.print("Enter your UserName: ");
        this.userName=sc.nextLine();
        System.out.print("Enter your password: ");
        this.password=sc.nextLine();
        System.out.print("Enter your account number: ");;
        this.accountNo=sc.nextInt();
        System.out.println("");
        System.out.println("Registration Completed Successfully Congratulation...!!");
        System.out.println("-------------------------------------------------------");
        System.out.println("Now Login to Your Account-->");
    }

    public boolean Login()
    {
        boolean isLogin=false;
        Scanner sc=new Scanner(System.in);
        while(!isLogin)
        {
            System.out.print("\nEnter your Username: ");
            String username=sc.nextLine();
            if(username.equals(userName))
            {
                while(!isLogin)
                {
                System.out.print("Enter your Password: ");
                String Password=sc.nextLine();
                if(Password.equals(password))
                {
                    System.out.println("\nLogged In Succesfully");
                    System.out.println("---------------------");
                    isLogin=true;
                    
                }    
                else
                {
                    System.out.println("Incorrect Password");
                }
                }
            }
            else
            {
                System.out.println("Sorry Username NOT FOUND!!!");
            }
        }
        return isLogin;
    }
    public void withdraw()
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the amount you want to withdraw: ");
        float amount=sc.nextFloat();
        try 
        {
            if(balance>=amount)
            {
                transactions++;
                balance=balance-amount;
                System.out.println("\nWithdrawal Succesfully...!\n");
                String str="Rs "+amount+" Withdrawn from your Account.\n";
                transactionHistroy=transactionHistroy.concat(str);
            }
            else
            {
                System.out.println("Insufficient Balance!!");
            }
        }
        catch(Exception e){

        }
    }
    public void deposite()
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the amount to be deposited: ");
        float amount=sc.nextFloat();
        try{
            if(amount<=100000f)
            {
                transactions++;
                balance=balance+amount;
                System.out.println("\nAmount Deposited Successfully.\n");
                String str="Rs "+amount+" Deposited in your Account.\n";
                transactionHistroy=transactionHistroy.concat(str);

            }
            else
            {
                System.out.println("Limit ids of 100000.00");
            }
        }
        catch(Exception e){
        }
    }
    public void transfer()
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the Recepient Name: ");
        String RepName=sc.nextLine();
        System.out.print("Enter the amount: ");
        float amount=sc.nextFloat();
        try
        {
            if(balance>=amount)
            {
                if(amount<=50000f)
                {
                    transactions++;
                    balance-=amount;
                    System.out.println("\nTransfered Sucessfully to "+RepName+".\n");
                    String str="Rs "+amount+" transfer to "+RepName+".";
                    transactionHistroy=transactionHistroy.concat(str);
                }
                 else
                {
                    System.out.println("SORRY Limit Is Of Rs 50000.00");
                }
            }
            else
            {
                System.out.println("Insuffient Balance");
            }
        }
        catch(Exception e){
    }
    }
    public void checkBalance()
    {
        System.out.println("\nBalance:--> "+balance);
        System.out.println("---------------------------");
    }
    public void transactionHis()
    {
        if(transactions==0)
        {
            System.out.println("Empty");
        }
        else
        {
            System.out.print("\n"+transactionHistroy+"\n");
            System.out.println("------------------------");
        }
    }
}
class ATMInterface
{
    public static int takeInetegerInput(int limit)
    {
        int input=0;
        boolean flag=false;
        while(!flag)
        {
            try
            {
               Scanner sc=new Scanner(System.in);
               input=sc.nextInt();
               flag=true;
               if(flag && input>limit || input<1)
               {
                System.out.print("Select The number between 1 and "+limit+":");
                flag=false;
               } 
            }
            catch(Exception e)
            {
                System.out.print("Enter Integer value: ");
                flag=false;
            }
        }
        return input;
    }
    public static void main(String [] args)
    {
        System.out.println("\n***** Welcome TO SBI ATM SYSTEM *****\n");
        System.out.println("1.REGISTER\n2.EXIT");
        System.out.println("---------------------");
        System.out.print("Enter Your Option: ");
        int choice=takeInetegerInput(2);
        if(choice==1)
        {
            Account b=new Account();
            b.Register();
            while(true)
            {
                System.out.println("1.LOGIN\n2.EXIT");
                System.out.println("------------------------");
                System.out.print("Enter Your Option: ");
                int ch=takeInetegerInput(2);
                if(ch==1)
                {
                    if(b.Login())
                    {
                        System.out.println("\n<----Welcome Back "+b.name+"---->");
                        boolean isFinish=false;
                        while(!isFinish)
                        {
                            System.out.print("O-P-T-I-O-N-S:-\n1.Deposit\n2.WithDraw\n3.Transfer\n4.Transaction Histroy\n5.Check balance\n6.Exit\n");
                            System.out.println("------------------");
                            System.out.print("Enter your option: ");
                            int c=takeInetegerInput(6);
                            switch(c)
                            {
                                case 1:
                                b.deposite();
                                break;
                                case 2:
                                b.withdraw();
                                break;
                                case 3:
                                b.transfer();
                                break;
                                case 4:
                                b.transactionHis();
                                break;
                                case 5:
                                b.checkBalance();
                                break;
                                case 6:
                                isFinish=true;
                                break;

                            }
                        }
                    }
                }
                else
                {
                    System.exit(0);
                }
            }
        }
        else
        {
           System.exit(0);
        }
    }
}
