import java.util.*;
public class Alternative {

	private String name;
	private ArrayList<Integer> successLevel = new ArrayList<Integer>();
	
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
}
