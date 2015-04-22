 class AppThreads extends Thread{
 
 	public void run(){
 		for(int i=0; i<10000; i++)
 			App.incCounter();
 	}	
 }
 
 class App{
 	static int counter = 0;
 	
 	static public void incCounter(){
 		counter++;
 	}
 
 	public static void main(String[] args){
 	
 		AppThreads[] appthreads = new AppThreads[1000];
 		for(int i=0; i<appthreads.length; i++){
 			appthreads[i] = new AppThreads();
 			appthreads[i].start();
 		}
 		
 		try{
 			for(int i=0; i< appthreads.length; i++){
 				appthreads[i].join();
 			}
 		}catch(InterruptedException e){
 			e.printStackTrace();
 		}
 		
 		System.out.println("Counter value is: "+counter);
 	}
 }
