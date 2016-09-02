class Solution{
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		BigInteger prod=new BigInteger("1");
		long tc=sc.nextInt();
		long count=0;
		long[] arr=new long[(int)tc];
		for(long i=0;i<tc;i++){long aa=sc.nextInt();arr[(int)i]=aa;
		if(aa!=0)prod=prod.multiply(BigInteger.valueOf(arr[(int)i]));else{count++;}
		}
	for(long i=0;i<tc;i++){
		BigInteger temp=new BigInteger("1");
		temp=prod;
		if(arr[(int)i]!=0 && count==0)
		temp=temp.divide(BigInteger.valueOf(arr[(int)i]));
		else if(arr[(int)i]!=0 && count>0)temp=BigInteger.ZERO;
		else if(count>1){temp=BigInteger.ZERO;}
		
	System.out.println(temp);}	
	}
	
	
}