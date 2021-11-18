
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

import Practica2.Espectaculo;
import Practica2.GestorEspectaculos;

public class ej2 {
    public static void main(String[] args) {

        System.out.println("Seleccione una opcion: ");
        System.out.println("1 ---> Usuario administrador");
        System.out.println("2 ---> Usuario espectador");

        Scanner sc = new Scanner(System.in);
        int usuario = sc.nextInt();

        //boolean exit = false;
        int bucle1 = 0;
        //UserManager userManager = UserManager.getUserManager();

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        GestorEspectaculos gestorEspectaculos = GestorEspectaculos.getInstance();

        if(usuario == 1) {
            while(bucle1 != 12) {
                // System.out.println("¿Que desea hacer?");
			    // System.out.println("1 ---> Iniciar Sesión");
			    // System.out.println("2 ---> Registrarse");

                switch(bucle1) {
                    case 1: {
                        // try {
                        //     System.out.println("Nombre de usuario: ");
                        //     String username = reader.readLine();
                            
                        //     System.out.println("Password: ");
                        //     String password = reader.readLine();
                            
                        //     if(userManager.login(username, password) == false) {
                        //         bucle1 = 0;
                        //         System.out.println("Datos erroneos");
                        //     }
                            
                        //     else {
                        //         userHasLoggedIn = true;
                        //     }
                
                        // } catch (IOException e) {
                        //     e.printStackTrace();
                        // }

                        try {
                            System.out.println("Introduce el titulo del espectaculo: ");
                            String title = reader.readLine();
                            
                            System.out.println("Introduce la descripcion del espectaculo: ");
                            String descriptition = reader.readLine();
                            
                            System.out.println("Introduce la categoria del espectaculo: ");
                            String category = reader.readLine();
                            
                            System.out.println("Introduce el aforo del espectaculo: ");
                            String aforo = reader.readLine();
                            int afo = Integer.parseInt(aforo);
                            
                            Espectaculo espectaculo = new Espectaculo(title, descriptition, category, afo);
                            gestorEspectaculos.AltaEspectaculo(espectaculo);
                
                        } catch (IOException e) {
                            e.printStackTrace();
                        }

                        break;
                    }

                    case 2: {
                        try {
                            System.out.println("Introduce el espectaculo que quieres cancelar: ");
                            String title = reader.readLine();

                            if(gestorEspectaculos.CancelarEspectaculo() == true) {
                                System.out.println("El espectaculo ha sido cancelado correctamente");
                            }
                            
                            else {
                                System.out.println("Error, no se ha encontrado el espectaculo.");
                            }

                        } catch (IOException e) { 
                            e.printStackTrace();
                        }

                        break;
                    }

                    case 3: {
                        try {
                            System.out.println("Introduce el nuevo titulo del espectaculo: ");
                            String newTitle = reader.readLine();
                            
                            System.out.println("Introduce la  nueva descripcion del espectaculo: ");
                            String newDescriptition = reader.readLine();
                            
                            System.out.println("Introduce la nueva categoria del espectaculo: ");
                            String newCategory = reader.readLine();
                            
                            System.out.println("Introduce el nuevo aforo del espectaculo: ");
                            String newAforo = reader.readLine();
                            int newAfo = Integer.parseInt(newAforo);
                            
                            Espectaculo nuevoEspectaculo = new Espectaculo(newTitle, newDescriptition, newCategory, newAfo);
                            gestorEspectaculos.ActualizarEspectaculo(nuevoEspectaculo);


                        } catch (IOException e) { 
                            e.printStackTrace();
                        }

                        break;
                    }

                    case 4: {
                        try {
                            System.out.println("Introduce el titulo del espectaculo del que quieras contabilizar las entradas vendidas: ");
                            String title = reader.readLine();

                            gestorEspectaculos.VentaEntradas(title);

                        } catch (IOException e) {
                            e.printStackTrace();
                        }

                        break;
                    }

                    case 5: {
                        try {
                            System.out.println("Introduce la fecha de representacion del espectaculo: ");
                            String fechaRepresentacion = reader.readLine();

                        } catch (IOException e) {
                            e.printStackTrace();
                        }

                        break;
                    }

                    case 6: {
                        try {
                            System.out.println("Introduce el titulo del espectaculo: ");
                            String title = reader.readLine();
        
                            ArrayList<Espectaculo> espectaculos;
                            espectaculos = gestorEspectaculos.BusquedaEspectaculosTitulo(title);
        
                            for (int i = 0; i < espectaculos.size(); i++){
                                System.out.println(espectaculos.get(i).getTitulo());
                                System.out.println(espectaculos.get(i).getDescripcion());
                                System.out.println(espectaculos.get(i).getCategoria());
                                System.out.println(espectaculos.get(i).getAforo());
                                System.out.println(espectaculos.get(i).getEntradasVendidas());
                                System.out.println(espectaculos.get(i).getLocalidad());
                            }
        
                        } catch (IOException e) {
                            e.printStackTrace();
                        }

                        break;
                    }

                    case 7: {
                        
                    }
                }
            }
        }

        if(usuario == 2) {

        }
    }
}
