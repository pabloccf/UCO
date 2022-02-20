package Ejerc1.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Ejerc1.src.DAOs.EspectaculoDAO;
import Ejerc1.src.Ej2.EspectaculoDTO;

/**
 * Servlet encargado de consultar los espectaculos disponibles de cada categoria
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/ConsultarEspectaculosDisponiblesCategoria")
public class ConsultarEspectaculosDisponiblesCategoria extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Este es el constructor del servlet
	 */
	public ConsultarEspectaculosDisponiblesCategoria() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.sendRedirect("/Ejercicio2/ConsultarEspectaculosCategoria.html");
	}

	/**
	 * Esta función del servlet es la encargada de utilizar las funciones del DAO de
	 * espectaculos para devolver una lista de todos los espectaculos
	 * 
	 * @param espectaculo1   es el objeto del tipo EspectaculoDTO que se utilizara
	 *                       para guardar la informacion de los diferentes
	 *                       espectaculos
	 * @param espectaculoDao es el objeto del tipo EspectaculoDAO que se utilizara
	 *                       para llamar a las funciones del DAO
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			String categoria = request.getParameter("categoria");

			ArrayList<EspectaculoDTO> espectaculo = new ArrayList<EspectaculoDTO>();
			ArrayList<EspectaculoDTO> espectaculosList = new ArrayList<EspectaculoDTO>();

			PrintWriter salida = response.getWriter();

			salida.println("<html>");
			salida.println("<title>Buscar Espectaculos Disponibles</title>");
			salida.println("<body>");

			EspectaculoDTO espectaculo1 = new EspectaculoDTO();
			espectaculo1.setCategoria(categoria);
			EspectaculoDAO espectaculoDao = new EspectaculoDAO();
			espectaculosList = espectaculoDao.ObtenerTodosEspectaculos();

			int variable = 1;

			if (!categoria.equals("")) {
				for (int x = 0; x < espectaculosList.size(); x++) {
					if (espectaculo1.getCategoria().equals(espectaculosList.get(x).getCategoria())) {
						if (espectaculosList.get(x).getEntradasVendidas() < espectaculosList.get(x).getAforo()) {
							variable++;
							espectaculo.add(espectaculosList.get(x));
						}
					}
				}
			}

			else {
				variable = 0;
			}

			if (variable > 1) {
				// salida.println("[");
				salida.println("<p>Espectaculos disponibles encontrados por categoria:</p>");
				for (int i = 0; i < espectaculo.size(); i++) {
					/*
					 * salida.println("{");
					 * salida.println("\"titulo\":\""+espectaculo.get(i).getTitulo()+"\",");
					 * salida.println("\"categoria\":\""+espectaculo.get(i).getCategoria()+"\",");
					 * salida.println("\"descripcion\":\""+espectaculo.get(i).getDescripcion()+"\","
					 * );
					 * salida.println("\"localidad\":\""+espectaculo.get(i).getLocalidad()+"\",");
					 * salida.println("\"aforo\":\""+espectaculo.get(i).getAforo()+"\",");
					 * salida.println("\"tipo espectaculo\":\""+espectaculo.get(i).getTipo()+"\",");
					 * salida.println("\"entradasVendidas\":\""+espectaculo.get(i).
					 * getEntradasVendidas()+"\",");
					 * salida.println("\"fecha\":\""+espectaculo.get(i).getFecha()+"\",");
					 * salida.println("\"hora inicio\":\""+espectaculo.get(i).getHora()+"\",");
					 */

					salida.println("<p>Titulo: " + espectaculo.get(i).getTitulo());
					salida.println("<br>");
					salida.println("Categoria: " + espectaculo.get(i).getCategoria());
					salida.println("<br>");
					salida.println("Descripcion: " + espectaculo.get(i).getDescripcion());
					salida.println("<br>");
					salida.println("Localidad: " + espectaculo.get(i).getLocalidad());
					salida.println("<br>");
					salida.println("Aforo: " + espectaculo.get(i).getAforo());
					salida.println("<br>");
					salida.println("Tipo de espectaculo: " + espectaculo.get(i).getTipo());
					salida.println("<br>");
					salida.println("Entradas vendidas: " + espectaculo.get(i).getEntradasVendidas());
					salida.println("<br>");
					salida.println("Fecha de inicio: " + espectaculo.get(i).getFecha());
					salida.println("<br>");
					salida.println("Hora de inicio: " + espectaculo.get(i).getHora());
					salida.println("<br>");

					if (espectaculo.get(i).getTipo().equals("Puntual")) {
						salida.println("Numero de espectaculos: " + espectaculo.get(i).getEspectaculos() + "</p>");
					}

					else if (espectaculo.get(i).getTipo().equals("Multiple")) {
						salida.println("Fecha de fin: " + espectaculo.get(i).getFechaFin());
						salida.println("<br>");
						salida.println("Hora de fin: " + espectaculo.get(i).getHoraFin());
						salida.println("<br>");
						salida.println("Numero de espectaculos: " + espectaculo.get(i).getEspectaculos() + "</p>");
					} else {
						salida.println("Fecha de fin: " + espectaculo.get(i).getFechaFin());
						salida.println("<br>");
						salida.println("Hora de fin: " + espectaculo.get(i).getHoraFin());
						salida.println("<br>");
						salida.println("Dia de la semana: " + espectaculo.get(i).getDia());
						salida.println("<br>");
						salida.println("Numero de espectaculos: " + espectaculo.get(i).getEspectaculos() + "</p>");
					}
					// salida.println(i==espectaculo.size()-1 ? "}" : "},");
				}

				// salida.println("]");
			}

			else if (variable == 0) {
				// salida.println("[");
				salida.println("<p>Espectaculos disponibles encontrados</p><br>");
				for (int i = 0; i < espectaculosList.size(); i++) {
					if (espectaculosList.get(i).getEntradasVendidas() < espectaculosList.get(i).getAforo()) {
						/*
						 * salida.println("{");
						 * salida.println("\"titulo\":\""+espectaculosList.get(i).getTitulo()+"\",");
						 * salida.println("\"categoria\":\""+espectaculosList.get(i).getCategoria()+
						 * "\",");
						 * salida.println("\"descripcion\":\""+espectaculosList.get(i).getDescripcion()+
						 * "\",");
						 * salida.println("\"localidad\":\""+espectaculosList.get(i).getLocalidad()+
						 * "\",");
						 * salida.println("\"aforo\":\""+espectaculosList.get(i).getAforo()+"\",");
						 * salida.println("\"tipo espectaculo\":\""+espectaculosList.get(i).getTipo()+
						 * "\",");
						 * salida.println("\"entradasVendidas\":\""+espectaculosList.get(i).
						 * getEntradasVendidas()+"\",");
						 * salida.println("\"fecha\":\""+espectaculosList.get(i).getFecha()+"\",");
						 * salida.println("\"hora inicio\":\""+espectaculosList.get(i).getHora()+"\",");
						 * if(espectaculosList.get(i).getTipo().equals("Puntual")) {
						 * salida.println("\"numero espectaculos\":\""+espectaculosList.get(i).
						 * getEspectaculos()+"\"");
						 * }
						 * 
						 * else if(espectaculosList.get(i).getTipo().equals("Multiple")){
						 * salida.println("\"fecha fin\":\""+espectaculosList.get(i).getFechaFin()+"\","
						 * );
						 * salida.println("\"hora fin\":\""+espectaculosList.get(i).getHoraFin()+"\",");
						 * salida.println("\"numero espectaculos\":\""+espectaculosList.get(i).
						 * getEspectaculos()+"\"");
						 * }
						 * else {
						 * salida.println("\"fecha fin\":\""+espectaculosList.get(i).getFechaFin()+"\","
						 * );
						 * salida.println("\"hora fin\":\""+espectaculosList.get(i).getHoraFin()+"\",");
						 * salida.println("\"hora fin\":\""+espectaculosList.get(i).getDia()+"\",");
						 * salida.println("\"numero espectaculos\":\""+espectaculosList.get(i).
						 * getEspectaculos()+"\"");
						 * }
						 * salida.println(i==espectaculosList.size()-1 ? "}" : "},");
						 */

						salida.println("Titulo: " + espectaculosList.get(i).getTitulo());
						salida.println("<br>");
						salida.println("Categoria: " + espectaculosList.get(i).getCategoria());
						salida.println("<br>");
						salida.println("Descripcion: " + espectaculosList.get(i).getDescripcion());
						salida.println("<br>");
						salida.println("Localidad: " + espectaculosList.get(i).getLocalidad());
						salida.println("<br>");
						salida.println("Aforo: " + espectaculosList.get(i).getAforo());
						salida.println("<br>");
						salida.println("Tipo de espectaculo: " + espectaculosList.get(i).getTipo());
						salida.println("<br>");
						salida.println("Entradas vendidas: " + espectaculosList.get(i).getEntradasVendidas());
						salida.println("<br>");
						salida.println("Fecha de inicio: " + espectaculosList.get(i).getFecha());
						salida.println("<br>");
						salida.println("Hora de inicio: " + espectaculosList.get(i).getHora());
						salida.println("<br>");

						if (espectaculosList.get(i).getTipo().equals("Puntual")) {
							salida.println(
									"Numero de espectaculos: " + espectaculosList.get(i).getEspectaculos() + "</p>");
						}

						else if (espectaculosList.get(i).getTipo().equals("Multiple")) {
							salida.println("Fecha de fin: " + espectaculosList.get(i).getFechaFin());
							salida.println("<br>");
							salida.println("Hora de fin: " + espectaculosList.get(i).getHoraFin());
							salida.println("<br>");
							salida.println(
									"Numero de espectaculos: " + espectaculosList.get(i).getEspectaculos() + "</p>");
						} else {
							salida.println("Fecha de fin: " + espectaculosList.get(i).getFechaFin());
							salida.println("<br>");
							salida.println("Hora de fin: " + espectaculosList.get(i).getHoraFin());
							salida.println("<br>");
							salida.println("Dia de la semana: " + espectaculosList.get(i).getDia());
							salida.println("<br>");
							salida.println(
									"Numero de espectaculos: " + espectaculosList.get(i).getEspectaculos() + "</p>");
						}
					}
				}
				// salida.println("]");
			}

			else {
				RequestDispatcher dispatcher = request
						.getRequestDispatcher("VentanaNoConsultarEspectaculosDisponiblesCategoria.html");
				dispatcher.include(request, response);
			}

			salida.println("</body></html>");
			RequestDispatcher dispatcher = request.getRequestDispatcher("plantilla.html");
			dispatcher.include(request, response);
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
