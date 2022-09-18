import java.net.*;
import java.io.*;

public class Myclient {
    public static void main(String[] args) throws Exception {
        URL server = new URL("http://www.google.co.in/");
        URLConnection x = server.openConnection();
        BufferedReader in = new BufferedReader(
                                new InputStreamReader(
                                x.getInputStream()));
        String inputLine;

        while ((inputLine = in.readLine()) != null) 
            System.out.println(inputLine);
        in.close();
    }
}