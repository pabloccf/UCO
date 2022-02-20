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
 * Servlet implementation class AltaEspectaculo
 */
@WebServlet("/AltaEspectaculo")
public class AltaEspectaculo extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AltaEspectaculo() {
        super();
        // TODO Auto-generated constructor stub
    }

    
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.sendRedirect("/Ejercicio2/espectaculoForm.html");
    }
    
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			EspectaculoDTO espectaculo = new EspectaculoDTO();
			
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
	    		}
	    		else {
	    			salida.println("El aforo y el numero de espectaculos no pueden ser 0");
	    		}
				
	    	}
			
	    	else if(tipo.equals("Multiple")) {
	    		if(aforo!=0 && numeroEspectaculos!=0) {
					for(int i=0; i<numeroEspectaculos;i++) {
			    		String fecha = request.getParameter("fecha");
						String hora = request.getParameter("hora");//Añadir a BD
						
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
					}
	    		}
	    		else {
	    			salida.println("El aforo y el numero de espectaculos no pueden ser 0");
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
						response.sendRedirect("/Ejercicio2/MenuPrincipal.html");

	    			}
	    			else {
	    				salida.println("Introduzca un dia de la semana valido (1-> Lunes, 7->Domingo");
	    			}
	    		}
	    		else {
	    			salida.println("El aforo y el numero de espectaculos no pueden ser 0");
	    		}

	    	}
			
		}catch (Exception e) {
            e.printStackTrace();
        }
		
	}

}
