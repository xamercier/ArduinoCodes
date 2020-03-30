package ca.xamercier.comm.utils;

import java.io.IOException;
import java.util.Scanner;

import org.json.JSONObject;

import ca.xamercier.comm.MainComm;

public class CommUtils {

	public static void read(Scanner data) {
		String value = null;
		try {
			value = data.nextLine().toString();
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println("Read from arduino: " + value);
		if(value.equals("PIN IS HIGH")) {
			JSONObject setLCD = new JSONObject();
			setLCD.put("action", "lcdWrite");
			setLCD.put("complInfo1", "THE PIN IS: ON");
			setLCD.put("complInfo2", "THE PIN IS: ON");
			send(setLCD.toString());
			
			JSONObject setMATRIX = new JSONObject();
			setMATRIX.put("action", "setMatrix");
			setMATRIX.put("complInfo1", "smile");
			setMATRIX.put("complInfo2", "");
			send(setMATRIX.toString());

		} else {
			JSONObject setLCD = new JSONObject();
			setLCD.put("action", "lcdWrite");
			setLCD.put("complInfo1", "THE PIN IS: OFF");
			setLCD.put("complInfo2", "THE PIN IS: OFF");
			send(setLCD.toString());
			
			JSONObject setMATRIX = new JSONObject();
			setMATRIX.put("action", "setMatrix");
			setMATRIX.put("complInfo1", "badsmile");
			setMATRIX.put("complInfo2", "");
			send(setMATRIX.toString());
		}
	}
	
	public static void send(String message){
		byte[] byteMessage = null;
		try {
			byteMessage = message.getBytes();
			MainComm.port.getOutputStream().write(byteMessage);
			MainComm.port.getOutputStream().flush();
			System.out.println("Sending to arduino: " + message);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
