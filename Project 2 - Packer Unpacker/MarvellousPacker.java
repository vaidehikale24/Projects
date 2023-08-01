// MarvellousPacker.java



import java.io.BufferedReader; 
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import java.io.File;
import java.io.FileInputStream; 
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Arrays;


public class MarvellousPacker 
{
    FileOutputStream outstream = null;

    String ValidExt[] = {".txt",".c","java","cpp"};

    public MarvellousPacker(String src, String Dest) throws Exception
    {
        byte Buffer[] = new byte[1024];
        int iRet = 0;
        boolean bRet = false;
        int PackCount = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("------------------ Packer Unpacker ------------------");

        System.out.println("Packing Activity of the application is started... ");

        System.out.println("Enter the name of folder which contains the files that you want to pack :  ");
        String FolderName =src;

        File fobj = new File(FolderName);
        String Header = null;

        System.out.println("Enter the name of packed file that you want to create : ");
        String PackFile = Dest;
           
        try
        {
            File Packobj = new File(PackFile);
            bRet = Packobj.createNewFile();

            if(bRet == false)
            {
                System.out.println("Unable to create packed file");
                return;
            }
            System.out.println("Packed file gets successfully created in your current directory");

            FileOutputStream outobj = new FileOutputStream(Packobj);

            bRet = fobj.isDirectory();
            if(bRet == true)
            {
                File list[] = fobj.listFiles();

                System.out.println("Total number of files found in the directory are : "+ list.length);

                for(int i = 0; i < list.length; i++)
                {
                    if((list[i].getName()).endsWith(".txt"))
                    {
                        Header = list[i].getName()+" "+list[i].length();
                        for(int j = Header.length();j < 100; j++)
                        {
                            Header = Header + " ";
                        }
                        byte bHeader[] =Header.getBytes();
                        outobj.write(bHeader,0,bHeader.length);
                        
                        FileInputStream inobj = new FileInputStream(list[i]);

                        //Loop tot write the data
                        while((iRet = inobj.read(Buffer)) != -1)
                        {
                            outobj.write(Buffer,0,iRet);
                        }

                        System.out.println("File successfully packed with name : "+list[i].getName());

                        inobj.close();
                        PackCount++;
                    }
                }
                System.out.println("------------------ Packing Summary ------------------");
                System.out.println("Total number of files scanned : "+list.length);
                System.out.println("Total number of files packed : "+PackCount);

                System.out.println("Thank you for using Packer Unpacker..");
            }   
        }
        catch(Exception iobj)
        {
            System.out.println("Exception occured : "+iobj);
        }

        // String Magic = "Marvellous11"; 
        // byte arr[]= Magic.getBytes(); 
        // File outfile =new File(Dest);

        // File infile = null;
        // outstream = new FileOutputStream(Dest); 
        // outstream.write(arr, 0, arr.length);

        // File folder = new File(src);

        // System.setProperty("user.dir",src); 
        // listAllFiles(src);   
    }   

    // public void listAllFiles(String path) 
    // {
    //     try
    //     (Stream<Path> paths = Files.walk (Paths.get(path)))
    //         {
    //             paths.forEach(filePath ->
    //             {
    //                 if(Files.isRegularFile(filePath))
    //                 {
    //                     try
    //                     {
    //                         String name= filePath.getFileName().toString(); 
    //                         String ext = name.substring(name.lastIndexOf("."));

    //                         List<String> list = Arrays.asList(ValidExt);

    //                         if(list.contains(ext))
    //                         {
    //                             File file=new File(filePath.getFileName().toString()); 
    //                             Pack(file.getAbsolutePath());
    //                         }
    //                     }
    //                     catch (Exception e) 
    //                     {
    //                         System.out.println(e);
    //                     }
    //                 }
                        
    //             });
    //         }
    //     catch (IOException e) 
    //     {
    //         System.out.println(e);
    //     }
    // }
    // public void Pack(String filePath) 
    // {
    //     FileInputStream instream = null;

    //     try
    //     {
    //         byte[] buffer = new byte[1024];

    //         int length;

    //         byte temp[]= new byte[100];

    //         File fobj = new File(filePath);

    //         String Header = filePath+" "+fobj.length();

    //         for (int i = Header.length(); i < 100; i++) 
    //             Header += " ";
                
    //         temp = Header.getBytes();

    //         instream = new FileInputStream(filePath); 

    //         outstream.write(temp, 0, temp.length); 
            
    //         while ((length = instream.read(buffer)) > 0) 
    //         {
    //             outstream.write(buffer, 0, length);
    //         }
    //         instream.close();
    //     }
    //     catch(Exception e)
    //     {
    //         System.out.println(e);
    //     }
    // }
}
