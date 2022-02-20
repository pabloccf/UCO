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
 * Servlet encargado de buscar espectaculo por titulo
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/BusquedaTituloCategoria")
public class BusquedaTituloCategoria extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Este es el constructor del servlet
	 */
	public BusquedaTituloCategoria() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * Esta función del servlet se encarga de llamar a las funciones del
	 * EspectaculoDAO necesarias para que se realize la acción, todo esto a partir
	 * de la información recibida
	 * 
	 * @param espectaculoDao y espect son los objetos tipo espectaculoDAO que se
	 *                       utilizan para llamar a funciones del DAO
	 * @param espectaculo    es el objeto tipo espectaculoDTO que se utiliza para
	 *                       guardar la información de un espectaculo
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// response.sendRedirect("/Ejercicio2/BusquedaTituloCategoria.html");
		try {
			EspectaculoDAO espectaculoDao = new EspectaculoDAO();
			EspectaculoDTO espectaculo = new EspectaculoDTO();

			EspectaculoDAO espect = new EspectaculoDAO();
			ArrayList<EspectaculoDTO> espectaculoList = espect.ObtenerTodosEspectaculos();
			ArrayList<EspectaculoDTO> espectaculoLista = new ArrayList<EspectaculoDTO>();

			int opcion = 0;
			int contador = 0;

			// HttpSession session = request.getSession();
			PrintWriter salida = response.getWriter();
			String buscar = request.getParameter("Busqueda");
			salida.println("<html>");
			salida.println("<title>Buscar Espectaculo</title>");
			salida.println("<body>");
			// salida.println("[");

			for (int i = 0; i < espectaculoList.size(); i++) {
				if (buscar.equals(espectaculoList.get(i).getTitulo())) {
					opcion = 1;

				} else if (buscar.equals(espectaculoList.get(i).getCategoria())) {
					opcion = 2;
					EspectaculoDTO e = espectaculoList.get(i);
					espectaculoLista.add(e);

				}
			}
			if (opcion == 1) {
				salida.println("<p>Espectaculo encontrado por titulo:</p>");
				espectaculo = espectaculoDao.obtenerMostrarPorTitulo(buscar);
				/**
				 * salida.println("{");
				 * salida.println("\"titulo\":\""+espectaculo.getTitulo()+"\",");
				 * salida.println("\"categoria\":\""+espectaculo.getCategoria()+"\",");
				 * salida.println("\"descripcion\":\""+espectaculo.getDescripcion()+"\",");
				 * salida.println("\"fecha\":\""+espectaculo.getFecha()+"\",");
				 * salida.println("\"localidad\":\""+espectaculo.getLocalidad()+"\",");
				 * salida.println("\"aforo\":\""+espectaculo.getAforo()+"\",");
				 * salida.println("\"entradasVendidas\":\""+espectaculo.getEntradasVendidas()+"\"");
				 * salida.println("}");
				 **/

				salida.println("<p>Titulo: " + espectaculo.getTitulo());
				salida.println("<br>");
				salida.println("Categoria: " + espectaculo.getCategoria());
				salida.println("<br>");
				salida.println("Descripcion: " + espectaculo.getDescripcion());
				salida.println("<br>");
				salida.println("Tipo de espectaculo: " + espectaculo.getTipo());
				salida.println("<br>");
				salida.println("Fecha: " + espectaculo.getFecha());
				salida.println("<br>");
				salida.println("Localidad: " + espectaculo.getLocalidad());
				salida.println("<br>");
				salida.println("Aforo: " + espectaculo.getAforo());
				salida.println("<br>");
				salida.println("Entradas vendidas: " + espectaculo.getEntradasVendidas() + "</p>");
				contador++;

			}

			// Busqueda por categoria
			else if (opcion == 2) {
				for (int i = 0; i < espectaculoLista.size(); i++) {
					/**
					 * salida.println("{");
					 * salida.println("\"titulo\":\""+espectaculoLista.get(i).getTitulo()+"\",");
					 * salida.println("\"categoria\":\""+espectaculoLista.get(i).getCategoria()+"\",");
					 * salida.println("\"descripcion\":\""+espectaculoLista.get(i).getDescripcion()+"\",");
					 * salida.println("\"fecha\":\""+espectaculoLista.get(i).getFecha()+"\",");
					 * salida.println("\"localidad\":\""+espectaculoLista.get(i).getLocalidad()+"\",");
					 * salida.println("\"aforo\":\""+espectaculoLista.get(i).getAforo()+"\",");
					 * salida.println("\"entradasVendidas\":\""+espectaculoLista.get(i).getEntradasVendidas()+"\"");
					 * salida.println(i==espectaculoLista.size()-1 ? "}" : "},");
					 **/
					salida.println("<p>Espectaculos encontrados por categoria:</p>");

					salida.println("<p>Titulo: " + espectaculoLista.get(i).getTitulo());
					salida.println("<br>");
					salida.println("Categoria: " + espectaculoLista.get(i).getCategoria());
					salida.println("<br>");
					salida.println("Descripcion: " + espectaculoLista.get(i).getDescripcion());
					salida.println("<br>");
					salida.println("Tipo de espectaculo: " + espectaculoLista.get(i).getTipo());
					salida.println("<br>");
					salida.println("Fecha: " + espectaculoLista.get(i).getFecha());
					salida.println("<br>");
					salida.println("Localidad: " + espectaculoLista.get(i).getLocalidad());
					salida.println("<br>");
					salida.println("Aforo: " + espectaculoLista.get(i).getAforo());
					salida.println("<br>");
					salida.println("Entradas vendidas: " + espectaculoLista.get(i).getEntradasVendidas() + "</p>");
					contador++;

				}
			}

			else {
				response.setStatus(404);
				// salida.println("Lo sentimos, no esta disponible dicho espectaculo");
			}
			salida.println("</body></html>");

			if (contador == 0) {
				RequestDispatcher dispatcher = request.getRequestDispatcher("VentanaEspectaculoNoEncontrado.html");
				dispatcher.include(request, response);
			}
			RequestDispatcher dispatcher = request.getRequestDispatcher("plantilla.html");
			dispatcher.include(request, response);
			// salida.println("]");
			// session.setAttribute("userDTO", userDTO);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.sendRedirect("/Ejercicio2/BusquedaTituloCategoria.html");
		/*
		 * try {
		 * EspectaculoDAO espectaculoDao = new EspectaculoDAO();
		 * EspectaculoDTO espectaculo = new EspectaculoDTO();
		 * 
		 * EspectaculoDAO espect = new EspectaculoDAO();
		 * ArrayList<EspectaculoDTO> espectaculoList =
		 * espect.ObtenerTodosEspectaculos();
		 * ArrayList<EspectaculoDTO> espectaculoLista = new ArrayList<EspectaculoDTO>();
		 * 
		 * int opcion=0;
		 * 
		 * //HttpSession session = request.getSession();
		 * PrintWriter salida=response.getWriter();
		 * String buscar = request.getParameter("Busqueda");
		 * salida.println("[");
		 * 
		 * for(int i=0; i<espectaculoList.size();i++) {
		 * if(buscar.equals(espectaculoList.get(i).getTitulo())) {
		 * opcion=1;
		 * 
		 * }
		 * else if(buscar.equals(espectaculoList.get(i).getCategoria())) {
		 * opcion=2;
		 * EspectaculoDTO e = espectaculoList.get(i);
		 * espectaculoLista.add(e);
		 * 
		 * }
		 * }
		 * if(opcion==1) {
		 * espectaculo = espectaculoDao.obtenerMostrarPorTitulo(buscar);
		 * salida.println("{");
		 * salida.println("\"titulo\":\""+espectaculo.getTitulo()+"\",");
		 * salida.println("\"categoria\":\""+espectaculo.getCategoria()+"\",");
		 * salida.println("\"descripcion\":\""+espectaculo.getDescripcion()+"\",");
		 * salida.println("\"fecha\":\""+espectaculo.getFecha()+"\",");
		 * salida.println("\"localidad\":\""+espectaculo.getLocalidad()+"\",");
		 * salida.println("\"aforo\":\""+espectaculo.getAforo()+"\",");
		 * salida.println("\"entradasVendidas\":\""+espectaculo.getEntradasVendidas()+
		 * "\"");
		 * salida.println("}");
		 * 
		 * 
		 * /*salida.println("Titulo: "+espectaculo.getTitulo());
		 * salida.println("<br><br>");
		 * salida.println("Categoria: "+espectaculo.getCategoria());
		 * salida.println("<br><br>");
		 * salida.println("Descripcion: "+espectaculo.getDescripcion());
		 * salida.println("<br><br>");
		 * salida.println("Fecha: "+espectaculo.getFecha());
		 * salida.println("<br><br>");
		 * salida.println("Localidad: "+espectaculo.getLocalidad());
		 * salida.println("<br><br>");
		 * salida.println("Aforo: "+espectaculo.getAforo());
		 * salida.println("<br><br>");
		 * salida.println("Entradas vendidas: "+espectaculo.getEntradasVendidas());
		 */

	}/*
		 * 
		 * //Busqueda por categoria
		 * else if(opcion==2) {
		 * for(int i=0; i<espectaculoLista.size();i++) {
		 * salida.println("{");
		 * salida.println("\"titulo\":\""+espectaculoLista.get(i).getTitulo()+"\",");
		 * salida.println("\"categoria\":\""+espectaculoLista.get(i).getCategoria()+
		 * "\",");
		 * salida.println("\"descripcion\":\""+espectaculoLista.get(i).getDescripcion()+
		 * "\",");
		 * salida.println("\"fecha\":\""+espectaculoLista.get(i).getFecha()+"\",");
		 * salida.println("\"localidad\":\""+espectaculoLista.get(i).getLocalidad()+
		 * "\",");
		 * salida.println("\"aforo\":\""+espectaculoLista.get(i).getAforo()+"\",");
		 * salida.println("\"entradasVendidas\":\""+espectaculoLista.get(i).
		 * getEntradasVendidas()+"\"");
		 * salida.println(i==espectaculoLista.size()-1 ? "}" : "},");
		 * 
		 * 
		 * /*salida.println("Titulo: "+espectaculoLista.get(i).getTitulo());
		 * salida.println("<br><br>");
		 * salida.println("Categoria: "+espectaculoLista.get(i).getCategoria());
		 * salida.println("<br><br>");
		 * salida.println("Descripcion: "+espectaculoLista.get(i).getDescripcion());
		 * salida.println("<br><br>");
		 * salida.println("Fecha: "+espectaculoLista.get(i).getFecha());
		 * salida.println("<br><br>");
		 * salida.println("Localidad: "+espectaculoLista.get(i).getLocalidad());
		 * salida.println("<br><br>");
		 * salida.println("Aforo: "+espectaculoLista.get(i).getAforo());
		 * salida.println("<br><br>");
		 * salida.println("Entradas vendidas: "+espectaculoLista.get(i).
		 * getEntradasVendidas());
		 * salida.println("<br><br>");
		 */

	// }
	// }
	/*
	 * 
	 * else{
	 * response.setStatus(404);
	 * //salida.println("Lo sentimos, no esta disponible dicho espectaculo");
	 * }
	 * salida.println("]");
	 * 
	 * //session.setAttribute("userDTO", userDTO);
	 * }catch (Exception e) {
	 * e.printStackTrace();
	 * }
	 * 
	 * }
	 */

}
