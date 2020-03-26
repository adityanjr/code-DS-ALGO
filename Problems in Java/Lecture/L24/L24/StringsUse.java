package L24;

public class StringsUse {

	public static void main(String[] args) {
		String s = "abcd";
//		System.out.println(s.startsWith("abce"));
		s.concat("defg");
		System.out.println(s);
		
		StringBuffer sb = new StringBuffer();
		sb.append("abcd");
		sb.append("defg");
		System.out.println(sb);
		sb.insert(1, "test");
		System.out.println(sb);
		sb.reverse();
		System.out.println(sb);
		sb.setCharAt(0, 'z');
		System.out.println(sb);
		s = sb.toString();
		System.out.println(s);
		System.out.println(s.substring(5));
	}
}
