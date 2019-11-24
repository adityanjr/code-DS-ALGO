import java.util.*;
import java.util.Map.Entry;
import java.lang.*;
import java.util.ArrayList;

public class Analyzer
{
    ArrayList<String> ar;
    Analyzer(ArrayList<String> ar1)
    {
        ar = ar1;
    }
    public ArrayList<String> return_final_ar()
    {
        LinkedHashMap<String, Integer> l_hm= new LinkedHashMap<String, Integer>();
        for (String str : ar)
        {
            if (!l_hm.containsKey(str))
            {
                l_hm.put(str, Collections.frequency(ar, str));
            }
        } 
        Sort sort_ar = new Sort();
        List<Entry<String, Integer>> ls = new LinkedList<Entry<String, Integer>>(l_hm.entrySet());
        Collections.sort(ls, sort_ar);
        ar.clear();
        for(Entry ent : ls)
        {
            ar.add((String)ent.getKey());
        }
        return ar;
    }
    public class Sort implements Comparator<Entry<String, Integer>>
    {
        @Override
        public int compare(Entry<String, Integer> s1, Entry<String, Integer> s2)
        {
            if (s1.getValue() == s2.getValue())
            {
                return s1.getKey().compareTo(s2.getKey());
            }
            return (s1.getValue() - s2.getValue())*-1;
        }
    }
}

class Main
{
    public static void main(String[] args)
    {
        ArrayList<String> ar = new ArrayList<String>();
        // ar.add("i");
        // ar.add("love");
        // ar.add("leetcode");
        // ar.add("i");
        // ar.add("love");
        // ar.add("coding");
        ar.add("the");
        ar.add("day");
        ar.add("is");
        ar.add("sunny");
        ar.add("the");
        ar.add("the");
        ar.add("the");
        ar.add("sunny");
        ar.add("is");
        ar.add("is");
        Analyzer analyzer = new Analyzer(ar);
        ar = analyzer.return_final_ar();
        System.out.println(ar);

    }
}