import java.io.*;
import java.util.ArrayList;
import java.util.Random;

public class BinaryFileSort {

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Please provide input and output files");
            System.exit(0);
        }

        String inputFile = args[0];
        String outputFile = args[1];
        Random ran = new Random();

        try (InputStream inputStream = new FileInputStream(inputFile);
                OutputStream outputStream = new FileOutputStream(outputFile);) {

            long fileSize = new File(inputFile).length();
            File i = new File(inputFile);
            

            byte[] allBytes = new byte[(int) fileSize];
            int fileInt = (int) fileSize;

            inputStream.read(allBytes);

            for (int x = 0; x < fileSize; x++) {
                System.out.println(Integer.toBinaryString(allBytes[x]));
                int ranInt = ran.nextInt(fileInt);
                allBytes[x] = allBytes[ranInt];
            }
            outputStream.write(allBytes);
            File d = new File(outputFile);
            i.delete();
            d.renameTo(i);

        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    public static void Read() {
        FileInputStream i;
        try {
            i = new FileInputStream("C:\\Users\\User\\SamShermanJava\\java-projects\\src\\file.bin");
            System.out.println(new DataInputStream(i).readLine());
            i.close();
        } catch (IOException e) {
            System.err.println("Unable to read from file");
            System.exit(-1);
        }
    }
}