import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main
{
    private static final String verb = "(hate|love|know|like)s*";
    private static final String noun= "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
    private static final String article = "(a|the)";
    private static final String actor = "(" + noun + "|" + article + " " + noun + ")";
    private static final String active_list = "(" + actor + " and )*" + actor;
    private static final String action = active_list + " " + verb + " " + active_list;
    private static final String statement = action + "( , " + action + ")*";
    public static void main(String args[])
    {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        String s;
        while (sc.hasNext())
        {
            s = sc.nextLine();
            if (s.matches(statement))
            {
                pr.println("YES I WILL");
            }
            else
            {
                pr.println("NO I WON'T");
            }
        }
        pr.flush();
    }
}
