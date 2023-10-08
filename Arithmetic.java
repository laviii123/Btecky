class Arithmetic{
	
	float arithmetic(){
		float n1 = 658,n2 = 80;

		float sum = n1+n2;
		float sub = n1-n2;
		float mul = n1*n2;
		float div = n1/n2;
		float mod = n1%n2;

		System.out.print("The sum is :"+sum);
		System.out.print("\nThe subtraction is :"+sub);
		System.out.print("\nThe multiplication is :"+mul);
		System.out.print("\nThe division is :"+div);
		System.out.print("\nThe modulo is :"+mod);

		return 0;
		

	}
	public static void main(String args[]){
		
		Arithmetic ar = new Arithmetic();

		System.out.println(ar.arithmetic());
	}
}