

//Marvellous Unpack.java

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;
import java.io.FileInputStream; 
import java.io.FileOutputStream;

public class MarvellousUnpack
{
    FileOutputStream outstream = null;

    public MarvellousUnpack(String src) throws Exception
    {

        byte Header[] = new byte[100];
        int iRet = 0;
        String HeaderStr;
        String Tokens[];
        int iCount = 0;

        System.out.println("----------- Marvellous Packer Unpacker ----------- ");
        System.out.println("Unpacking Actvity of the appication is started...");

        System.out.println("Enter the file name which contains the packed data : ");
        String PackFile = src;

        try
        {
            File Packobj = new File(PackFile);
            FileInputStream inobj = new FileInputStream(Packobj);

            while((iRet = inobj.read(Header,0,100)) > 0)
            {
                HeaderStr = new String(Header);
                System.out.println(HeaderStr);

                Tokens = HeaderStr.split(" ");

                File newfileobj = new File(Tokens[0]);
                newfileobj.createNewFile();

                FileOutputStream outobj = new FileOutputStream(newfileobj);
                int FileSize = Integer.parseInt(Tokens[1]);
                byte Buffer[] = new byte [FileSize];

                inobj.read(Buffer,0, FileSize);
                outobj.write(Buffer,0,FileSize);

                System.out.println("File successfully extracted with name : "+Tokens[0]);
                iCount++;
            }
            System.out.println("------------------ UnPacking Summary ------------------");
            System.out.println("Total number of files extracted : "+iCount);

            System.out.println("Thank you for using Packer Unpacker..");
        }
        catch(Exception obj)
        {
            System.out.println("Exception occured : "+obj);
        }
    }
    // public void unpack(String filePath) throws Exception
    // {
    //     try
    //     {
    //         FileInputStream instream = new FileInputStream(filePath);

    //         byte header[]= new byte[100];
    //         int length=0;

    //         byte Magic[] = new byte[12];
    //         instream.read(Magic,0,Magic.length);

    //         String Magicstr = new String(Magic);

    //         if(!Magicstr.equals("Marvellous11"))
    //         {
    //             throw new InvalidFileException("Invalid packed file format");
    //         }

    //         while((length = instream.read(header,0,100))> 0)
    //         {
    //             String str = new String(header); 

    //             String ext= str.substring(str.lastIndexOf("/")); 
    //             ext = ext.substring(1);

    //             String[] words = ext.split("\\s");

    //             String filename = words[0];

    //             int size = Integer.parseInt(words[1]);

    //             byte arr[] = new byte[size]; 
                
    //             instream.read(arr,0,size);
                
    //             FileOutputStream fout=new FileOutputStream(filename); 
    //             fout.write(arr,0,size);
    //         }
    //     }
    //     catch(InvalidFileException obj)
    //     {
    //         throw new InvalidFileException("Invalid packed file format");
    //     }
    //     catch(Exception e)
    //     {}
    // }
}
