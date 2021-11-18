package Ejerc1.src.Ej2;

import java.io.*;
import java.sql.SQLException;
import java.util.Scanner;

/**
 * Es el programa principal o main el cual tiene el menú de interacción con el usuario
 * @author Pablo López Gosálvez, Pablo Ibañez Fernández-Delgado y José Ángel Dorado González
 * @version openjdk version 11.0.12 2021-07-20
 */

public class Ej2 {
	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		UserManager userManager = UserManager.getUserManager();
		int bucle1 = 0;
		Scanner reader2 = new Scanner(System.in);
		Scanner opc1 = new Scanner(System.in);

		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		GestorEspectaculos gestorEspectaculos = GestorEspectaculos.getInstance();
		
		boolean userHasLoggedIn = false;
		TipoUsuario tu;
		
		int aux = 0;
		String tipo;
				
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
							UserDTO usuario = new UserDTO();
							usuario = userManager.ObtenerUsuario(username);
							
							if(usuario.getTipoAsString().equals("ADMINISTRADOR")) {
								aux = 1;
							}

							else if(usuario.getTipoAsString().equals("ESPECTADOR")) {
								aux = 2;
							}
						}
			
					} catch (IOException e) {
						e.printStackTrace();
					}

					break;
				}

				case 2: {
					//Leer datos y crear el usuario con ellos
					try {
						UserDTO usuario = new UserDTO();
						int opc = 0;

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
						
						System.out.println("Que tipo de usuario deseas ser: ");
						System.out.println("1.-Administrador ");
						System.out.println("2.-Espectador");
						
						opc = opc1.nextInt();
						
						if(opc == 1) {
							tu = TipoUsuario.ADMINISTRADOR;
							usuario.setTipo(tu);	
							aux = 1;
							tipo = "ADMINISTRADOR";
							usuario.setTipoAsString(tipo);
						}

						else if(opc == 2) {
							tu = TipoUsuario.ESPECTADOR;
							usuario.setTipo(tu);
							aux = 2;
							tipo = "ESPECTADOR";
							usuario.setTipoAsString(tipo);
						}
											
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
		
		int bucle2 = -1;
		int bucle3 = -1;

		Scanner reader3 = new Scanner(System.in);
		
		GestorCritica gestorCritica = GestorCritica.getInstance();
		
		if(aux == 1) {
			while(bucle2 != 0){
				System.out.println("1.-Crear espectaculo");
				System.out.println("2.-Cancelar espectaculo");
				System.out.println("3.-Actualizar Espectaculo");
				System.out.println("4.-Consultar localidades disponibles");
				System.out.println("5.-Buscar espectaculo(Por titulo)");
				System.out.println("6.-Buscar espectaculo(Por categoria)");
				System.out.println("7.-Publicar una critica");
				System.out.println("8.-Consultar criticas");
				System.out.println("9.-Eliminar critica");
				System.out.println("10.-Valorar critica");
				System.out.println("0.-Salir");	
				
				bucle2 = reader3.nextInt();
				
				switch(bucle2) {
				
					case 1: {
						try {
							EspectaculoDTO espectaculo = new EspectaculoDTO();

							System.out.println("Introduce el titulo del espectaculo: ");
							espectaculo.setTitulo(reader.readLine());
							
							System.out.println("Introduce la descripcion del espectaculo: ");
							espectaculo.setDescripcion(reader.readLine());
							
							System.out.println("Introduce la categoria del espectaculo: ");
							espectaculo.setCategoria(reader.readLine());
							
							System.out.println("Introduce el aforo del espectaculo: ");
							String aforo = reader.readLine();
							int afo = Integer.parseInt(aforo);
							espectaculo.setAforo(afo);
							
							System.out.println("Introduce la localidad del espectaculo: ");
							espectaculo.setLocalidad(reader.readLine());
							
							System.out.println("Introduce la fecha del espectaculo (utiliza el formato DD/MM/AAAA):");
							espectaculo.setFecha(reader.readLine());
							
							
							gestorEspectaculos.AltaEspectaculo(espectaculo);
							
						} catch (IOException e) {
							e.printStackTrace();
						}

						break;
					}
					
					case 2: {
						try {
							System.out.println("Introduce el titulo del espectaculo que deseas eliminar: ");
							String titleReview = reader.readLine();
							
							EspectaculoDTO espectaculo = gestorEspectaculos.BusquedaEspectaculosTitulo(titleReview);
							gestorEspectaculos.CancelarEspectaculo(espectaculo);
							
							System.out.println("¡El espectaculo ha sido cancelado de manera exitosa!");

						
						}catch (IOException e) {
							e.printStackTrace();
						}
						
						break;
					}
					
					case 3: {
						try {
							System.out.println("Introduce el titulo del espectaculo que desea actualizar: ");
							String newTitle1 = reader.readLine();
							
							System.out.println("Introduce el nuevo titulo del espectaculo: ");
							String newTitle = reader.readLine();
							
							System.out.println("Introduce la  nueva descripcion del espectaculo: ");
							String newDescriptition = reader.readLine();
							
							System.out.println("Introduce la nueva categoria del espectaculo: ");
							String newCategory = reader.readLine();
							
							System.out.println("Introduce el nuevo aforo del espectaculo: ");
							String newAforo = reader.readLine();
							int newAfo = Integer.parseInt(newAforo);
							
							EspectaculoDTO nuevoEspectaculo = new EspectaculoDTO(newTitle, newDescriptition, newCategory, newAfo);
							gestorEspectaculos.ActualizarEspectaculo(nuevoEspectaculo,newTitle1);
							
						}						
						catch (IOException e) {
							e.printStackTrace();
						}

						break;
					}
					
					case 4: {
						try {
							System.out.println("Introduce una fecha para buscar las localidades disponibles (utiliza el formato DD/MM/AAAA)");
							String fecha = reader.readLine();
							
							if(gestorEspectaculos.BusquedaEspectaculosFecha(fecha)==0) {
								System.out.println("Lo sentimos, no se ha encontrado ningun espectaculo para la fecha seleccionada");
							}
						} catch (IOException e) {
							e.printStackTrace();
						}
						
						break;
					}
					
					case 5: {
						try {
							System.out.println("Introduce el titulo del espectaculo que deseas buscar: ");
							String titleReview = reader.readLine();
							
							EspectaculoDTO espectaculo = gestorEspectaculos.BusquedaEspectaculosTitulo(titleReview);
							System.out.println("Titulo: "+espectaculo.getTitulo());
							System.out.println("Descripcion: "+espectaculo.getDescripcion());
							System.out.println("Categoria: "+espectaculo.getCategoria());
							System.out.println("Aforo: "+espectaculo.getAforo());
							System.out.println("Entradas vendidas: "+espectaculo.getEntradasVendidas());
							System.out.println("Localidad: "+espectaculo.getLocalidad());
							System.out.println("Fecha: "+espectaculo.getFecha());
							System.out.println("\n");
						} catch (IOException e) {
							e.printStackTrace();
						}

						break;
					}

					case 6:{
						try {
							
							System.out.println("Introduce la categoria del espectaculo que deseas buscar: ");
							String categoria = reader.readLine();
							
							EspectaculoDTO espectaculo = gestorEspectaculos.BusquedaEspectaculosCategoria(categoria);
							System.out.println("Titulo: "+espectaculo.getTitulo());
							System.out.println("Descripcion: "+espectaculo.getDescripcion());
							System.out.println("Categoria: "+espectaculo.getCategoria());
							System.out.println("Aforo: "+espectaculo.getAforo());
							System.out.println("Entradas vendidas: "+espectaculo.getEntradasVendidas());
							System.out.println("Localidad: "+espectaculo.getLocalidad());
							System.out.println("Fecha: "+espectaculo.getFecha());
							System.out.println("\n");

						} catch (IOException e) {
							e.printStackTrace();
						}

						break;
					}

					case 7:{
						try {
							CriticaDTO nuevaCritica = new CriticaDTO();
							
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

					case 8:{
						gestorCritica.mostrarCriticas();
						break;
					}

					case 9:{
						try {
							System.out.println("Introduce el titulo de la critica que deseas eliminar: ");
							String titleReview = reader.readLine();
							gestorCritica.EliminarCritica(titleReview);
							System.out.println("La critica ha sido eliminada correctamente");

						} catch (IOException e) {
							e.printStackTrace();
						}

						break;
					}

					case 10:{
						try {
							System.out.println("Introduce el titulo de la critica que deseas valorar: ");
							String titleReview = reader.readLine();
							
							CriticaDTO review;
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
				}//fin switch
			}
		}

		else if(aux == 2){
			while(bucle3 != 0){
				
				System.out.println("1.-Publicar critica");
				System.out.println("2.-Valorar critica");
				System.out.println("3.-Ver informacion sobre espectaculos");
				System.out.println("4.-Comprar entrada");
				System.out.println("0.-Salir");	
				
				bucle3 = reader3.nextInt();
				
				switch(bucle3) {
					case 1:{
						try {
							CriticaDTO nuevaCritica = new CriticaDTO();
							
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

					case 2:{
						try {
							System.out.println("Introduce el titulo de la critica que deseas valorar: ");
							String titleReview = reader.readLine();
							
							CriticaDTO review;
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

					case 3:{
						gestorEspectaculos.MostrarEspectaculos();
						break;
					}

					case 4:{
						try {
							System.out.println("Introduce el titulo del espectaculo del que desea comprar una entrada: ");
							String entradaTitulo = reader.readLine();
						
							System.out.println("Introduce el numero de entradas a comprar: ");
							String Numero = reader.readLine();
							int entradaNumero = Integer.parseInt(Numero);
							
							if(gestorEspectaculos.ComprarEntrada(entradaNumero, entradaTitulo)) {
								System.out.println("¡Entradas compradas! \n");
							}

							else {
								System.out.println("Lo sentimos, no puede comprar entradas de ese espectaculo porque no esta disponible o el aforo esta completo\n");

							}
						} catch (IOException e) {
							e.printStackTrace();
						}

						break;
					}
				}
			}
			
			opc1.close();
			reader2.close();
			reader3.close();
		}
	}
}