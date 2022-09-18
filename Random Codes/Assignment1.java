import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Assignment1{
	public static void main(String args[]) throws IOException 
	{

        ServerSocket server = new ServerSocket(80); 
            try (Socket socket = server.accept()) 
			{
			String httpResponse = "HTTP/1.1 200 OK\r\n\r\n" + "<!DOCTYPE html> <html> <head> <title>SE20UECE110_Assignment1</title> </head> <body><h1>Name:- Vinay Nallana</h1><h2>Roll Number:- SE20UECE110</h2><p>Web Technologies Assignment1 complete.</p></body></html>";
               
                socket.getOutputStream().write(httpResponse.getBytes("UTF-8"));
			}
	}

}
