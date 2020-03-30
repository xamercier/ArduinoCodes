package ca.xamercier.comm.utils;

import ca.xamercier.comm.MainComm;

public class readThread extends Thread{
	
	@Override
	public void run() {
		while (MainComm.data.hasNextLine()) {
			CommUtils.read(MainComm.data);
		}
	}

}
