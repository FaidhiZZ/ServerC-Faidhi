import java.io.*;
import java.net.*;



public class client {


    public static void main(String[] args) throws IOException {


    final int PORT_NUMBER = 666;

    final String HOSTNAME = "192.168.43.75";


    //Connecting to socket

    try {


        Socket sock = new Socket(HOSTNAME, PORT_NUMBER);


        PrintWriter out = new PrintWriter(sock.getOutputStream(),true);


        BufferedReader in = new BufferedReader(new InputStreamReader(sock.getInputStream()));


	//Send output to the server


        out.println("\n Bonjour")
        out.flush();

	System.out.println(in.readLine());

       	out.close();
	in.close();
	sock.close();



    } catch(Exception e) {



        e.printStackTrace();


    }

   }
