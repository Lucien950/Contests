import java.util.*;
import java.io.*;
public class coinGame {

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new File("s4.in"));
		PrintWriter output = new PrintWriter(new BufferedWriter(new FileWriter(new File("s4.out"))));
		int length;
			while((length = Integer.parseInt(input.nextLine())) != 0){
				Set s = new Set();
				s.add(input.nextLine().replaceAll(" ", "/") + "/");
				int count = BFS(s, new Set(),0,length);
					if (count>=0) output.println(count);
					else output.println("IMPOSSIBLE");
			}
			
			output.close();

	}
	
	public static int BFS(Set current, Set used, int depth, int length){
		if (current.contains(generateFinal(length))) return(depth);
		else if(current.isEmpty()) return(-1);

		Set newDepth = new Set();
		used.addAll(current);
			for(String s:current) newDepth.addAll(findChildren(s,length));
		newDepth.removeAll(used);
		return(BFS(newDepth,used,depth+1,length));
	}
	
	public static Set findChildren(String parent, int boardLength){
		Set children = new Set();
		String[] data = parent.split("/");
			
				for(int x = 0; x<data.length-1;x++){
					String[] array = data.clone();
						if(validMove(array[x],array[x+1])) children.add(processString(array,x,x+1));
						else if (validMove(array[x+1],array[x])) children.add(processString(array,x+1,x));
				}
			
			
		return(children);
	}
	
	public static boolean validMove(String mover, String stack){
		if (mover.equals(" ")) return(false);
		else if (stack.equals(" ")) return(true);
		else return(Integer.parseInt(mover)%10<Integer.parseInt(stack)%10);
	}
	
	public static String generateFinal(int n){
		String config = "";
		for(int x = 1; x<=n;x++) config += x + "/";
		return (config);
	}
	
	public static String processString(String[] data, int moveIndex, int stackIndex){
		Integer num = Integer.parseInt(data[moveIndex].substring(data[moveIndex].length()-1));
		data[moveIndex] = data[moveIndex].substring(0,data[moveIndex].length()-1);
		data[stackIndex]+= num.toString();
		data[stackIndex] = data[stackIndex].trim();
		String temp = "";
			for(String s: data)
				if (s.isEmpty()) temp+=" /";
				else temp+=s + "/";
		
			return(temp);
	}

	public static class Set extends HashSet<String>{}
}
