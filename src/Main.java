import java.util.*;
public class Main {

	static Scanner scan = new Scanner(System.in);
	static ArrayList<User> users = new ArrayList<User>();
	
	
	
	
	public static void main(String[] args) {

		initialize();
		makeUsers();
		getAlternatives();
		int counter = 0;
		for(User user: users)
		{
			if(users.size() > 1)
			{
				userMessage(counter);
			}
			getCriteriaAndWeights(user);
			getAlternativeSuccess(user);
			multiply(user);
			counter++;
		}
		if(users.size() > 1)
		{
			getGroupDecision();
		}
		
	}
	
	private static void userMessage(int num)
	{
		space();
		if(num > 0)
		{
			System.out.println("Group member " + num + " has completed their part.");
			pressEnter("Please switch to the next group member, and press enter to continue. ");
		}
		else
		{
			System.out.println("Now it is time for each group member to give their input. Pick one group member to begin.");
			pressEnter("Press enter to continue.");
		}
	}
	
	private static void initialize()
	{
		System.out.println("Welcome to Decision Maker! This app will help you make decisions, as an individual or group.");
		pressEnter("Press enter to continue. ");
	}
	
	private static void getGroupDecision()
	{
		space();
		pressEnter("We have determined the best group decision. Please press enter for the final result.");
		int[] totals = new int[users.size()];
		
		for(User user:users)
		{
			int counter = 0;
			for(Alternative alt: user.getAlternatives())
			{
				totals[counter] = alt.getTotal();
				counter++;
			}
		}
		int highest = -1;
		int highestIndex = -1;
		for(int i = 0; i < totals.length; i++)
		{
			if(totals[i] > highest)
			{
				highest = totals[i];
				highestIndex = i;
			}
		}
		
		System.out.println("Taking into account each person's input, the best group decision would be \"" + users.get(0).getAlternatives().get(highestIndex).getName() + "\"");
	}
	
	private static void makeUsers()
	{
		int input = readInt("Please enter the number of people in the group that is making the decision. If only you are making the decision, type \"1\": ");
		for(int i = 0; i < input; i++)
		{
			User user = new User();
			users.add(user);
		}
	}
	
	private static void getAlternatives()
	{
		space();
		System.out.println("Please input the name of all of the alternatives that you are considering.");
		if(users.size() > 1)
		{
			System.out.println("Please note that the entire group should agree on these alternatives.");
		}
		System.out.println("Once you have inputted all of your alternatives, type \"done\".");
		int i = 1;
		ArrayList<String> alternatives = new ArrayList<String>();
		while(true)
		{
			String input = readLine("Alternative " + i + ": ");
			
			if(input.equalsIgnoreCase("done"))
			{
				break;
			}
			
			alternatives.add(input);
			i++;
		}
		for(User user: users)
		{
			for(String alt: alternatives)
			{
				user.addAlternative(alt);
			}
		}
		
	}
	
	private static void getCriteriaAndWeights(User user)
	{
		space();
		System.out.println("Please enter each of the criteria that you will use to evaluate the alternatives.");
		System.out.println("After each criteria, enter a number from 1-100 to denote the importance of that criteria, with higher values corresponding to higher importance.");
		System.out.println("Type \"done\" when you are finished");
		while(true)
		{
			String input  = readLine("Criteria: ");
			if(input.equalsIgnoreCase("done"))
			{
				break;
			}
			int weight = 0;
			while(true)
			{
				weight = readInt("Weight: ");
				if(!(weight < 0 || weight > 100))
				{
					break;
				}
				System.out.println("Please enter a number between 1 and 100");
			}
			
			user.addCriteria(input, weight);
		}
	}
	
	private static void getAlternativeSuccess(User user)
	{
		space();
		System.out.println("Great! Now, you will need to evaluate how well each alternative fulfills the criteria.");
		System.out.println("Enter a number from 1-100. A higher number should correspond to better fulfillment of the criteria.");
		for(Alternative alternative: user.getAlternatives())
		{
			
			for(String theCriteria: user.getCriteria().keySet())
			{
				System.out.println("How well does the \"" + alternative.getName() + "\" alternative fulfill the \"" + theCriteria + "\" criteria? ");
				int success;
				while(true)
				{
					 success = readInt("");
					 if(!(success < 0 || success > 100))
					 {
						  break;
					 }
					System.out.println("Please enter a number between 1 and 100");
				}
				
				alternative.addSuccess(success);
			}
		}
	}
	
	private static void multiply(User user)
	{
		
		for(Alternative alternative: user.getAlternatives())
		{
			int i = 0;
			for(int critWeight: user.getCriteria().values())
			{
				alternative.addToTotal(critWeight * alternative.getSuccess().get(i));
				i++;
			}
		}
		pressEnter("Great job. We have your results. Press enter to continue.");
		System.out.println("Here are the point values for each alternative: ");
		int highest = 0;
		String highestAlt = "";
		for(Alternative alternative: user.getAlternatives())
		{
			System.out.println(alternative.getName() + ": " + alternative.getTotal());
			if(highest < alternative.getTotal())
			{
				highest = alternative.getTotal();
				highestAlt = alternative.getName();
			}
		}
		System.out.println();
		System.out.println("Based on these results, you would most likely prefer this alternative: ");
		System.out.println(highestAlt);
		pressEnter("Press enter to continue.");
	}
	public static String pressEnter(String prompt){
		System.out.print(prompt);
		return scan.nextLine();
	}
	public static String readLine(String prompt){
		while(true){
			String input = pressEnter(prompt);
			if(!input.equals(""))
			{
				return input;

			}
			System.out.println("Please enter a valid input.");
		}
	}
	public static int readInt(String prompt){

		while(true){
			String input = pressEnter(prompt);
			try {
				int n = Integer.parseInt(input);
				return n;
			} catch (Exception e){
				System.out.println("Please enter a number.");

			}
		}
	}
	public static void space()
	{
		System.out.println("---");
	}
	
	
	
	

}
