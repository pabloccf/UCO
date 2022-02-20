package Ejerc1.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet encargado de cerrar sesión
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/CerrarSesion")
public class CerrarSesion extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Este es el constructor del servlet
	 */
	public CerrarSesion() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * Esta funcion es la que se encarga de sacar al usuario de su sesión
	 * redirigiendolo a la raiz del proyecto
	 * 
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			request.getSession().invalidate();
			response.sendRedirect("/Ejercicio2/iniciarSesio.html"); // lo redirige a la raiz del proyecto (SE PUEDE
																	// REDIRECCIONAR DE OTRAS MANERAS)
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
