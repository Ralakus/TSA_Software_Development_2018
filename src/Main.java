import java.util.*;
public class Main {

	static Scanner scan = new Scanner(System.in);
	private static ArrayList<Alternative> alternatives = new ArrayList<Alternative>();
	private static HashMap<String, Integer> criteria = new HashMap<String, Integer>();
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		getAlternatives();
		getCriteriaAndWeights();
		getAlternativeSuccess();
		multiply();
		
		
		
		
		
	}
	
	private static void getAlternatives()
	{
		System.out.println("Please input the name of one of the alternatives that you are considering.");
		System.out.println("If you have inputted all of your alternatives already, type \"done\".");
		int i = 1;
		while(true)
		{
			System.out.println("Alternative " + i + ": ");
			String input = readLine("");
			
			if(input.equals("done"))
			{
				break;
			}
			
			Alternative alt = new Alternative(input);
			alternatives.add(alt);
			i++;
		}
		
	}
	
	private static void getCriteriaAndWeights()
	{
		System.out.println("Now, please enter each of the criteria that you will use to evaluate the alternatives.");
		System.out.println("After each criteria, enter a number from 1-100 to denote the importance of that criteria, with higher values corresponding to higher importance.");
		System.out.println("Type \"done\" when you are finished");
		while(true)
		{
			System.out.println("Criteria: ");
			String input  = readLine("");
			if(input.equals("done"))
			{
				break;
			}
			System.out.println("Weight: ");
			Integer weight = readInt("");
			criteria.put(input, weight);
		}
	}
	
	private static void getAlternativeSuccess()
	{
		System.out.println("Great! Now, you will need to evaluate how well each alternative fulfills the criteria.");
		System.out.println("Enter a number from 1-100. A higher number should correspond to better fulfillment of the criteria.");
		for(Alternative alternative: alternatives)
		{
			System.out.println("Alternative: " + alternative.getName());
			for(String theCriteria: criteria.keySet())
			{
				System.out.println("Criteria: " + theCriteria);
				int success = readInt("");
				alternative.addSuccess(success);
			}
		}
	}
	
	private static void multiply()
	{
		
		for(Alternative alternative: alternatives)
		{
			int i = 0;
			for(int critWeight: criteria.values())
			{
				alternative.addToTotal(critWeight * alternative.getSuccess().get(i));
				i++;
			}
		}
		System.out.println("Great job. We have your results. Here are the point values for each alternative: ");
		int highest = 0;
		String highestAlt = "";
		for(Alternative alternative: alternatives)
		{
			System.out.println(alternative.getName() + ": " + alternative.getTotal());
			if(highest < alternative.getTotal())
			{
				highest = alternative.getTotal();
				highestAlt = alternative.getName();
			}
		}
		System.out.println();
		System.out.println("Based on these results, we recommend this alternative: ");
		System.out.println(highestAlt);
	}
	public static String readLine(String prompt){
		System.out.print(prompt);
		return scan.nextLine();
	}
	public static int readInt(String prompt){

		while(true){
			String input = readLine(prompt);
			try {
				int n = Integer.parseInt(input);
				return n;
			} catch (Exception e){

			}
		}
	}
	
	
	
	

}
