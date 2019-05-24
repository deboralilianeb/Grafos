/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package forca;

/**
 *
 * @author debora
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Random;


public class Tarefa02 {
    
    
    public void Cliente(Socket cs) throws IOException {
        
        OutputStream outputStream = cs.getOutputStream();
        InputStream inputStream = cs.getInputStream();
        BufferedReader bf = new BufferedReader(new InputStreamReader(inputStream));
        
        
        //conjunto de palavras do jogo
         ArrayList<String> palavras = new ArrayList(); 
         palavras.add("TELEGRAFO");
         palavras.add("COMPUTADOR");
         palavras.add("RESIDENCIAL");
         palavras.add("JANELA");
         palavras.add("POLITICA");
         palavras.add("MOTOCICLETA");
         palavras.add("FILTRO");
        
         //numero de palavras
         Integer n = palavras.size();
         
         //sorteando uma palavra
         Random random = new Random();
         Integer posicao = random.nextInt(n);
         String palavraSorteada = palavras.get(posicao);
         
         //tamanho da palavra sorteada
         Integer tamPalavraSorteada = palavraSorteada.length();
         //System.out.println(palavraSorteada);
         
         outputStream.write("\nPara sair digite: FIM\n\n".getBytes());
       
         outputStream.write("A palavra tem : ".getBytes());
         outputStream.write(tamPalavraSorteada.toString().getBytes());
         outputStream.write(" letras\n".getBytes());
            
         
        for (int i = 0; i < tamPalavraSorteada; i++)
        {
          outputStream.write("_ ".getBytes());  
        }
        
        outputStream.write("\n".getBytes());
            
        Integer numTentativasErradas = 0;
        String userline;
            
        char letrasPalavraSorteada [] = palavraSorteada.toCharArray();
            
        //vetor para guardar letras que o jogador acetou
        Character[] acertos = new Character[tamPalavraSorteada];
            
        //preenchendo o vetor de acertos com undescore '_'
        for (int i = 0; i < acertos.length; i++) 
        {
            acertos[i]='_';
           
        }
                 
        Integer tentativas=0;
        Integer numeroAcertos=0;
        Integer chances =6;
            
        while(true)
        {   
            int cont=0;
                
            outputStream.write("\nEscreva uma letra: \n".getBytes());
            userline = bf.readLine().toUpperCase();
            tentativas+=1;
                
            if("FIM".equals(userline))
            {   
                outputStream.write("A palavra era ".getBytes());
                outputStream.write(palavraSorteada.getBytes());
                outputStream.write("\n".getBytes());
                cs.close();
                System.out.println("Conexão Encerrada...");
            }
             
            //tranformando a string para um vetor de char
            char letra [] = userline.toCharArray();
            
            //verificando se a letra pertence a palavra
            for (int i = 0; i < tamPalavraSorteada; i++) 
            {
                if(letra[0]==letrasPalavraSorteada[i])     
                   {
                       acertos[i]=letra[0];
                       numeroAcertos++;
                   }
               //incrementa o contador de erros
                else
                    cont++;
                     
            }
               
            //SE o numero de acertos for igual ao tamanho da palavra sorteada 
            //o usuário venceu
            if(numeroAcertos.equals(tamPalavraSorteada))
                {   
                    outputStream.write(palavraSorteada.getBytes());
                    outputStream.write("\n\nVocê venceu!\n".getBytes());
                    outputStream.write("\n".getBytes());
                    outputStream.write("\n".getBytes());
                    cs.close();
                    break;
                  
                }   
                
            //se o contador igual ao tamanho da palavra sorteada nenhuma a letra chutada
           //não pertence a palavra sorteada
            if(cont==tamPalavraSorteada)
            {
                    outputStream.write("\nQue pena, você errou!\n".getBytes());
                    numTentativasErradas++;
                    chances=chances-1;
                     
                    if(numTentativasErradas.equals(1))
                    {
                        outputStream.write("..... /////......\n".getBytes());
                        outputStream.write("....(.o..o.).....\n".getBytes());
                    }
                 
                    if(numTentativasErradas.equals(2))
                    {
                        outputStream.write("..... /////......\n".getBytes());
                        outputStream.write("....(.o..o.).....\n".getBytes());
                        outputStream.write(".......|||.........\n".getBytes());
                        outputStream.write(".......|||........\n".getBytes());
                                  
                    }
                                
                    if(numTentativasErradas.equals(3))
                    {
                        outputStream.write("..... /////......\n".getBytes());
                        outputStream.write("....(.o..o.).....\n".getBytes());
                        outputStream.write("....//.|||.........\n".getBytes());
                        outputStream.write(".......|||........\n".getBytes());
                                  
                    }
                                
                    if(numTentativasErradas.equals(4))
                    {
                        outputStream.write("..... /////......\n".getBytes());
                        outputStream.write("....(.o..o.).....\n".getBytes());
                        outputStream.write("....//.|||.\\\\...\n".getBytes());
                        outputStream.write(".......|||........\n".getBytes());
                                    
                    }
                                
                    if(numTentativasErradas.equals(5))
                    {
                        outputStream.write("..... /////......\n".getBytes());
                        outputStream.write("....(.o..o.).....\n".getBytes());
                        outputStream.write("....//.|||.\\\\...\n".getBytes());
                        outputStream.write(".......|||........\n".getBytes());
                        outputStream.write(".....//.......\n".getBytes());
                    }
                     
                    if(numTentativasErradas.equals(6))
                    {
                        outputStream.write("..... /////......\n".getBytes());
                        outputStream.write("....(.o..o.).....\n".getBytes());
                        outputStream.write("....//.|||.\\\\........\n".getBytes());
                        outputStream.write(".......|||........\n".getBytes());
                        outputStream.write(".....//..\\\\.....\n".getBytes());
                                    
                                    
                        outputStream.write("Você perdeu!!\n Atingiu a quantidade maxima de erros.\n Inicie outra partida\n\n".getBytes());
                        outputStream.write(palavraSorteada.getBytes());
                                   
                        cs.close();
                        System.out.println("Conexão Encerrada");
                        break;
                                   
                     }
                               
                   }
                
              
                outputStream.write("Você ainda tem ".getBytes());
                outputStream.write(chances.toString().getBytes());
                outputStream.write(" vida(s)\n".getBytes());
                
                for (Character acerto : acertos) 
                {
                    outputStream.write(' ');
                    outputStream.write(acerto);
                }
        
            }      
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       
        Tarefa02 server = new Tarefa02();
        int port = 60000;
        try {
            
            ServerSocket chatServer = new ServerSocket(port);
            while(true)
            {
                System.out.println("Esperando cliente");
                Socket clientSocket = chatServer.accept();
                System.out.println("Cliente conectou");
                server.Cliente(clientSocket);
                
            }
        } catch(Exception e) {
            System.out.println("Erro.");
            
            e.toString();
            System.out.println(e.toString());
        }
    }
    

}