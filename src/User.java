import java.util.ArrayList;
import java.util.HashMap;

public class User {

	private HashMap<String, Integer> criteria = new HashMap<String, Integer>();
	private ArrayList<Alternative> alternatives = new ArrayList<Alternative>();
	
	public User()
	{
		
	}
	
	public ArrayList<Alternative> getAlternatives()
	{
		return alternatives;
	}
	
	public void addAlternative(String name)
	{
		Alternative alternative = new Alternative(name);
		alternatives.add(alternative);
	}
	
	public HashMap<String, Integer> getCriteria()
	{
		return criteria;
	}
	
	public void addCriteria(String name, int weight)
	{
		criteria.put(name, (Integer) weight);
	}
}

