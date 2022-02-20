package Ejerc1.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Ejerc1.src.DAOs.EspectaculoDAO;
import Ejerc1.src.Ej2.EspectaculoDTO;


/**
 * Servlet encargado de crear espectaculos
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/AltaEspectaculo")
public class AltaEspectaculo extends HttpServlet {
	private static final long serialVersionUID = 1L;
    int contador=0;
	EspectaculoDTO espectaculo1 = new EspectaculoDTO();
	EspectaculoDTO espectaculo = new EspectaculoDTO();


	/**
     * Es el constructor del servlet.
     */
    public AltaEspectaculo() {
        super();
        // TODO Auto-generated constructor stub
    }

    
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    		if(contador==0) {
        		response.sendRedirect("/Ejercicio2/espectaculoForm.html");
    		}
    		else {
        		response.sendRedirect("/Ejercicio2/EspectaculoMultipleFormulario.html");
    		}
    }
    
    /**
     * Esta función del servlet es la encargada de llamar a las funciones necesarias
     * para poder crear un nuevo espectaculo
     * 
     * @param espectaculo Es el objeto tipo espectaculo de espectaculoDTO que
     *                    guardara la informacion.
     * @throws IOException Señala que se ha producido una excepción de E/S de algún
     *                     tipo. Esta clase es la clase general de excepciones
     *                     producidas por operaciones de E/S fallidas o
     *                     interrumpidas
     * 
     */
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			if(contador==0) {
				
				String titulo = request.getParameter("titulo");
				String categoria = request.getParameter("categoria");
				String descripcion = request.getParameter("descripcion");
				String localidad = request.getParameter("localidad");
				String aforo_str = request.getParameter("aforo");
		    	int aforo = Integer.parseInt(aforo_str);
		    	String tipo = request.getParameter("tipo"); //Añadir a BD
		    	int entradasVendidas = 0;
		    	String numeroEspectaculos_str = request.getParameter("numeroEspectaculos");
				int numeroEspectaculos = Integer.parseInt(numeroEspectaculos_str);
		    				
	            PrintWriter salida=response.getWriter();
				
	            
		    	if(tipo.equals("Puntual")) {
		    		if(aforo!=0 && numeroEspectaculos!=0) {
						String fecha = request.getParameter("fecha");
						String hora = request.getParameter("hora");//Añadir a BD
						 numeroEspectaculos = 1;
						
						espectaculo.setTitulo(titulo);
						espectaculo.setCategoria(categoria);
						espectaculo.setDescripcion(descripcion);
						espectaculo.setLocalidad(localidad);
						espectaculo.setAforo(aforo);
						espectaculo.setTipo(tipo);
						espectaculo.setEspectaculos(numeroEspectaculos);
						espectaculo.setFecha(fecha);
						espectaculo.setHora(hora);
						espectaculo.setEntradasVendidas(entradasVendidas);
										
						EspectaculoDAO e = new EspectaculoDAO();
						e.crearEspectaculo(espectaculo);
						response.sendRedirect("/Ejercicio2/ejemploVentana.html");
	
		    		}
		    		else {
		    			salida.println("El aforo y el numero de espectaculos no pueden ser 0");
		    		}
					
		    	}
				
		    	else if(tipo.equals("Multiple")) {
		    		if(aforo!=0 && numeroEspectaculos!=0 && contador<=numeroEspectaculos) {
				    		String fecha = request.getParameter("fecha");
							String hora = request.getParameter("hora");//Añadir a BD
							
							if(contador==0) {
								 	espectaculo1.setTitulo(titulo);
									espectaculo1.setCategoria(categoria);
									espectaculo1.setDescripcion(descripcion);
									espectaculo1.setLocalidad(localidad);
									espectaculo1.setAforo(aforo);
									espectaculo1.setTipo(tipo);
									espectaculo1.setEspectaculos(numeroEspectaculos);
									espectaculo1.setEntradasVendidas(entradasVendidas);
							}
							
							espectaculo.setTitulo(espectaculo1.getTitulo());
							espectaculo.setCategoria(espectaculo1.getCategoria());
							espectaculo.setDescripcion(espectaculo1.getDescripcion());
							espectaculo.setLocalidad(espectaculo1.getLocalidad());
							espectaculo.setAforo(espectaculo1.getAforo());
							espectaculo.setTipo(espectaculo1.getTipo());
							espectaculo.setEspectaculos(espectaculo1.getEspectaculos());
							espectaculo.setFecha(fecha);
							espectaculo.setHora(hora);
							espectaculo.setEntradasVendidas(espectaculo1.getEntradasVendidas());
		
							
							EspectaculoDAO e = new EspectaculoDAO();
							e.crearEspectaculo(espectaculo);
							contador++;
							if(contador!=numeroEspectaculos) {
								doGet(request, response);
							}
							else {
								response.sendRedirect("/Ejercicio2/ejemploVentana.html");
							}
		    		}
	
	
		    		
		    	}
		    	
		    	else if(tipo.equals("Temporada")) {
		    		if(aforo!=0 && numeroEspectaculos!=0) {
		    			String fecha = request.getParameter("fecha");
			    		String fechaFin = request.getParameter("fechaFin");
			    		String dia_str = request.getParameter("dia");
			    		int dia = Integer.parseInt(dia_str);
						String hora = request.getParameter("hora");//Añadir a BD
						String horaFin = request.getParameter("horaFin"); 
		    			numeroEspectaculos = 1;
		    			
		    			if(dia>=1 && dia<=7) {
							espectaculo.setTitulo(titulo);
							espectaculo.setCategoria(categoria);
							espectaculo.setDescripcion(descripcion);
							espectaculo.setLocalidad(localidad);
							espectaculo.setAforo(aforo);
							espectaculo.setTipo(tipo);
							espectaculo.setEspectaculos(numeroEspectaculos);
							espectaculo.setFecha(fecha);
							espectaculo.setHora(hora);
							espectaculo.setFechaFin(fechaFin);
							espectaculo.setHoraFin(horaFin);
							espectaculo.setDia(dia);
							espectaculo.setEntradasVendidas(entradasVendidas);
						
							EspectaculoDAO e = new EspectaculoDAO();
							e.crearEspectaculo(espectaculo);
							response.sendRedirect("/Ejercicio2/ejemploVentana.html");
	
		    			}
		    			else {
		    				salida.println("Introduzca un dia de la semana valido (1-> Lunes, 7->Domingo");
		    			}
		    		}
		    		else {
		    			salida.println("El aforo y el numero de espectaculos no pueden ser 0");
		    		}
	
		    	}
		    	
			}
			else {
	    		if(espectaculo1.getTipo().equals("Multiple")) {
		    		if(espectaculo1.getAforo()!=0 && espectaculo1.getEspectaculos()!=0 && contador<=espectaculo1.getEspectaculos()) {
				    		String fecha = request.getParameter("fecha");
							String hora = request.getParameter("hora");//Añadir a BD
						
							
							espectaculo.setTitulo(espectaculo1.getTitulo());
							espectaculo.setCategoria(espectaculo1.getCategoria());
							espectaculo.setDescripcion(espectaculo1.getDescripcion());
							espectaculo.setLocalidad(espectaculo1.getLocalidad());
							espectaculo.setAforo(espectaculo1.getAforo());
							espectaculo.setTipo(espectaculo1.getTipo());
							espectaculo.setEspectaculos(espectaculo1.getEspectaculos());
							espectaculo.setFecha(fecha);
							espectaculo.setHora(hora);
							espectaculo.setEntradasVendidas(espectaculo1.getEntradasVendidas());
		
							
							EspectaculoDAO e = new EspectaculoDAO();
							e.crearEspectaculo(espectaculo);
							contador++;
							if(contador!=espectaculo1.getEspectaculos()) {
								doGet(request, response);
							}
							else {
								response.sendRedirect("/Ejercicio2/ejemploVentana.html");
							}
		    		}
	
	
		    		
		    	}
		    	
	    	}
			
		}catch (Exception e) {
            e.printStackTrace();
        }
		
	}

}