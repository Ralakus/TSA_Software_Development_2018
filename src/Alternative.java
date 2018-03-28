import java.util.*;
public class Alternative {

	private String name;
	private ArrayList<Integer> successLevel = new ArrayList<Integer>();
	private int total = 0;
	
	public Alternative(String name)
	{
		this.name = name;
	}
	
	public String getName()
	{
		return name;
	}
	
	public void addSuccess(int success)
	{
		successLevel.add(success);
	}
	
	public ArrayList<Integer> getSuccess()
	{
		return successLevel;
	}
	
	public void addToTotal(int num)
	{
		total+=num;
	}
	
	public int getTotal()
	{
		return total;
	}
}
