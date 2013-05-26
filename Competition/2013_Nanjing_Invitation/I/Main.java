import java.util.Scanner;
import java.util.TreeMap;

public class Main {
	static void doAssignment(String str){
		String[] arr = str.split("=", 2);
		String name = arr[0].trim();
		String value = arr[1].trim();
		if (name.charAt(0) == '$'){
			vmap.put(name, value);
		}else{
			String ret = cmap.get(name);
			if (ret == null){
				cmap.put(name, value);
			}else{
				if (error){
					System.out.println("WARNING: Constant "+name+" Already Defined!");
				}
			}
		}
	}
	static void doPrint(String str){
		if (str.charAt(0) == '$'){
			String ret = vmap.get(str);
			if (ret == null){
				System.out.println("NULL");
				if (error){
					System.out.println("NOTICE: Undefined Variable "+str+".");
				}
			}else{
				if (ret.charAt(0) == '"'){
					System.out.println(ret.substring(1, ret.length()-1));
				}else{
					System.out.println(ret);
				}
			}
		}else{
			String ret = cmap.get(str);
			if (ret == null){
				System.out.println(str);
				if (error){
					System.out.println("NOTICE: Undefined Constant "+str+".");
				}
			}else{
				if (ret.charAt(0) == '"'){
					System.out.println(ret.substring(1, ret.length()-1));
				}else{
					System.out.println(ret);
				}
			}
		}
	}
	static void doDump(String str){
		if (str.charAt(0) == '$'){
			String ret = vmap.get(str);
			if (ret == null){
				System.out.println("NULL");
				if (error){
					System.out.println("NOTICE: Undefined Variable "+str+".");
				}
			}else{
				if (ret.charAt(0) == '"'){
					System.out.println("string: "+ret);
				}else{
					System.out.println("integer: "+ret);
				}
			}
		}else{
			String ret = cmap.get(str);
			if (ret == null){
				System.out.println("string: \""+str+"\"");
				if (error){
					System.out.println("NOTICE: Undefined Constant "+str+".");
				}
			}else{
				if (ret.charAt(0) == '"'){
					System.out.println("string: "+ret);
				}else{
					System.out.println("integer: "+ret);
				}
			}
		}
	}
	static void doErrmsg(String str){
		if (str.equals("ON")){
			error = true;
		}else{
			error = false;
		}
	}
	static void doTerminate(){
		System.out.println("Script was KILLED.");
		done = true;
	}
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		int n;
		String str;
		while (T-- != 0){
			vmap = new TreeMap<String, String>();
			cmap = new TreeMap<String, String>();
			n = cin.nextInt();
			done = false;
			error = true;
			for (int i = 0; i <= n; i++){
				str = cin.nextLine().trim();
				if (done) continue;
				if (str == null) continue;
				
				if (str.contains("=")){
					doAssignment(str);
					continue;
				}else if (str.equalsIgnoreCase("Panic")){
					doTerminate();
					continue;
				}
				
				String[] arr = str.split("\\s+", 2);
				if (arr[0].equalsIgnoreCase("Print")){
					doPrint(arr[1]);
				}else if (arr[0].equalsIgnoreCase("Dump")){
					doDump(arr[1]);
				}else if (arr[0].equalsIgnoreCase("Errmsg")){
					doErrmsg(arr[1]);
				}
			}
			if (T > 0) System.out.println();
		}
	}
	static TreeMap<String, String> vmap;
	static TreeMap<String, String> cmap;
	static boolean done;
	static boolean error;
}