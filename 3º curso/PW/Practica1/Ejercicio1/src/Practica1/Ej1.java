package Practica1;
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Es el programa principal o main el cual tiene el menu de interaccion con el usuario
 * @author José Ángel Dorado, Pablo López y Pablo Ibañez
 * @version openjdk 11.0.11 2021-04-20
 */
public class Ej1 {
	public static void main(String[] args) {
		
		UserManager userManager = UserManager.getUserManager();
		int bucle1 = 0;
		Scanner reader2 = new Scanner(System.in);

		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	
		boolean userHasLoggedIn = false;
		
		userManager.leerFich();
		
		while(!userHasLoggedIn) {
			
			System.out.println("¿Que desea hacer?");
			System.out.println("1 ---> Iniciar Sesión");
			System.out.println("2 ---> Registrarse");
			
			bucle1 = reader2.nextInt();
			
			switch(bucle1) {
			
			case 1: {
				//Leer
				try {
					System.out.println("Nombre de usuario: ");
					String username = reader.readLine();
					
					System.out.println("Password: ");
					String password = reader.readLine();
					
					if(userManager.login(username, password) == false) {
						System.out.println("Datos erroneos");
					}
					
					else {
						userHasLoggedIn = true;
					}
		
				} catch (IOException e) {
					e.printStackTrace();
				}
				break;
			}
				
				
			case 2: {
				//Leer datos y crear el usuario con ellos
		
				try {
					User usuario = new User();

					System.out.println("Nombre: ");
					
					usuario.setNombre(reader.readLine());
				
					System.out.println("Apellidos: ");
					usuario.setApellidos(reader.readLine());
				
					System.out.println("Email: ");
					usuario.setEmail(reader.readLine());
				
					System.out.println("Username: ");
					usuario.setUsername(reader.readLine());
				
					System.out.println("Password: ");
					usuario.setPassword(reader.readLine());
				
					userManager.registrar(usuario);
					userHasLoggedIn = true;

				} catch (IOException e) { 
					e.printStackTrace();
				}
				break;
			}
				
			default:
				
				System.out.println("Seleccione una opcion valida");

				break;
			}
		}
		
		GestorCritica gestorCritica = GestorCritica.getInstance();
		
		int bucle2 = -1;
		Scanner reader3 = new Scanner(System.in);
		gestorCritica.leerFichero();
		
		while(bucle2 != 0){
			
			System.out.println("1.-Crear critica");
			System.out.println("2.-Consultar críticas disponibles");
			System.out.println("3.-Borrar una crítica");
			System.out.println("4.-Valorar una crítica");
			System.out.println("5.-Buscar criticas");
			System.out.println("0.-Salir");	
			
			bucle2 = reader3.nextInt();
			
			switch(bucle2) {
			
				case 1: {
					
					try {
						Critica nuevaCritica = new Critica();
						
						System.out.println("Introduce el titulo de la critica: ");
						nuevaCritica.setTitulo(reader.readLine());
						
						System.out.println("Introduce la puntuacion de la critica: ");
						String puntuation = reader.readLine();
						int punt = Integer.parseInt(puntuation);
						nuevaCritica.setPuntuacion(punt);
						
						System.out.println("Introduce el texto de la critica: ");
						nuevaCritica.setTexto(reader.readLine());
						
						System.out.println("Introduce la valoracion de la critica con un numero del 0 al 5: ");
						String valoration = reader.readLine();
						int val = Integer.parseInt(valoration);
						nuevaCritica.setValoracion(val);
						
						System.out.println("Introduce el autor de la critica: ");
						nuevaCritica.setOwner(reader.readLine());
						
						nuevaCritica.setCantidadValoraciones(nuevaCritica.getCantidadValoraciones()+1);
						
						gestorCritica.CrearCritica(nuevaCritica);
			
					} catch (IOException e) {
						e.printStackTrace();
					}
					break;
				}
					
					
				case 2: {
					
					gestorCritica.mostrarCriticas();
		
					break;
				}
					
					
				case 3: {
					try {
					
					System.out.println("Introduce el titulo de la critica que deseas eliminar: ");
					String titleReview = reader.readLine();
					
					
					if(gestorCritica.EliminarCritica(titleReview) == true) {
						
						gestorCritica.escribirFichero();
						System.out.println("La critica ha sido eliminada correctamente");
					}
					
					else {
						System.out.println("Error, no se ha encontrado la critica.");
					}
		
					} catch (IOException e) {
						e.printStackTrace();
					}
					break;
				}
					
				case 4: {
					
					try {
						System.out.println("Introduce el titulo de la critica que deseas valorar: ");
	                    String titleReview = reader.readLine();
	
	                    Critica review;
	                    review = gestorCritica.ObtenerCritica(titleReview);
	
	                    System.out.println("Introduce una valoración entre 0 y 5 de la critica: ");
	                    String ratingReview_str = reader.readLine();
	                    int ratingReview = Integer.parseInt(ratingReview_str);
	
	                    if(ratingReview <= 0 || ratingReview > 5) {
	                        System.out.println("Error, debes introducir la valoracion entre 0 y 5. Vuelve a introducir la valoracion: ");
	                        ratingReview_str = reader.readLine();
	                        ratingReview = Integer.parseInt(ratingReview_str);
	                    }
	
	                    int ratingMedia = review.getValoracion();
	
	                    int cantidadValoraciones = review.getCantidadValoraciones();
	
	                    review.setValoracion(ratingMedia + ratingReview);
	                    review.setCantidadValoraciones(cantidadValoraciones + 1);
	
	                    System.out.println("La media de las valoraciones de los usuarios es: " + ((Integer)(review.getValoracion() / review.getCantidadValoraciones())).toString());
					
					} catch (IOException e) {
						e.printStackTrace();
					}
	                    
					break;
				}

				case 5: {
					try {
						System.out.println("Introduce el nombre de usuario: ");
						String username;
						username = reader.readLine();
	
						ArrayList<Critica> criticas;
						criticas = gestorCritica.buscarCriticasUsuario(username);
						
						
						for (int i = 0; i < criticas.size(); i++){
							System.out.println(criticas.get(i).getTitulo());
							System.out.println(criticas.get(i).getPuntuacion());
							System.out.println(criticas.get(i).getTexto());
							System.out.println(criticas.get(i).getValoracion());
							System.out.println(criticas.get(i).getOwner());
						}
						
					} catch (IOException e) {
						e.printStackTrace();
					}
					break;
				}
			}
		}
		reader2.close();
		reader3.close();
	}
}
