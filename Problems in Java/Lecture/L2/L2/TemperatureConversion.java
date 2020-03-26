import java.util.Scanner;

public class TemperatureConversion {

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		System.out.println("Enter starting Fahrenheit value");
		int startingFahrenheitValue = s.nextInt();
		System.out.println("Enter ending Fahrenheit value");
		int endingFahrenheitValue = s.nextInt();
		
		int fahrenheit = startingFahrenheitValue;
		while(fahrenheit <= endingFahrenheitValue) {
			int celsius = (int) ((5.0/9.0)*(fahrenheit - 32));
			
			/*System.out.print(fahrenheit);
			System.out.print("\t");
			System.out.println(celsius);*/
			
			System.out.println(fahrenheit + "\t" + celsius);
			
			fahrenheit = fahrenheit + 20;
		}
	}
}
