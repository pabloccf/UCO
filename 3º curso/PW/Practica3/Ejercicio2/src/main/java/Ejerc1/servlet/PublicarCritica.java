package Ejerc1.servlet;

import java.io.IOException;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Ejerc1.src.DAOs.CriticaDAO;
import Ejerc1.src.DAOs.EspectaculoDAO;
import Ejerc1.src.Ej2.CriticaDTO;
import Ejerc1.src.Ej2.EspectaculoDTO;

import java.util.*;
import java.text.*;

/**
 * Servlet encargado de publicar una critica
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/PublicarCritica")
public class PublicarCritica extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Es el constructor del servlet.
	 */
	public PublicarCritica() {
		super();
		// TODO Auto-generated constructor stub
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.sendRedirect("/Ejercicio2/criticaForm.html");

		// RequestDispatcher view =
		// request.getRequestDispatcher("/Ejercicio2/criticaForm.html");

		// view.forward(request, response);
	}

	/**
	 * Esta funcion del servlet utiliza las funciones de CriticaDAO para crear una
	 * nueva critica a partir de los datos que recibe
	 * 
	 * @param critica  es el objeto de tipo CriticaDAO que se va a utilizar para
	 *                 acceder a las funciones del DAO
	 * @param critica1 es el objeto de tipo CriticaDTO que se va a utilizar para
	 *                 almacenar la informacion de la critica
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub

		if (request.getSession(false) != null) {
			try {
				String fecha2;
				EspectaculoDTO espectaculo3 = new EspectaculoDTO();
				// Cadena con el formato deseado
				Date fecha = new Date(Calendar.getInstance().getTimeInMillis());
				SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd");
				String fechaTexto = formatter.format(fecha);

				EspectaculoDAO espectaculo1 = new EspectaculoDAO();
				ArrayList<EspectaculoDTO> lista = new ArrayList<EspectaculoDTO>();
				CriticaDAO critica = new CriticaDAO();
				CriticaDTO critica1 = new CriticaDTO();

				ArrayList<CriticaDTO> listaCriticas = new ArrayList<CriticaDTO>();

				String tituloEspectaculo = request.getParameter("titulo2");
				String titulo = request.getParameter("titulo");
				String puntuacion_str = request.getParameter("puntuacion");
				int puntuacion = Integer.parseInt(puntuacion_str);
				String texto = request.getParameter("texto");
				String valoracion_str = request.getParameter("valoracion");
				int valoracion = Integer.parseInt(valoracion_str);
				lista = espectaculo1.ObtenerTodosEspectaculos();
				for (int i = 0; i < lista.size(); i++) {
					if (tituloEspectaculo.equals(lista.get(i).getTitulo())) {
						espectaculo3.setFecha(lista.get(i).getFecha());
					}
				}

				fecha2 = espectaculo3.getFecha();

				// Formato deseado de la fecha del espectaculo
				SimpleDateFormat formato = new SimpleDateFormat("yyyy-MM-dd");
				Date date2 = formato.parse(fecha2);

				// Formato deseado de la fecha local
				SimpleDateFormat formato1 = new SimpleDateFormat("yyyy-MM-dd");
				Date date1 = formato1.parse(fechaTexto);

				if (date2.before(date1)) {
					listaCriticas = critica.ObtenerTodasCriticas();

					critica1.setTitulo(titulo);
					critica1.setPuntuacion(puntuacion);
					critica1.setTexto(texto);
					critica1.setValoracion(valoracion);
					critica1.setOwner((String) request.getSession().getAttribute("username"));
					critica1.setTituloEspectaculo(tituloEspectaculo);
					critica1.setCantidadValoraciones(1);

					for (int i = 0; i < listaCriticas.size(); i++) {
						if (tituloEspectaculo.equals(listaCriticas.get(i).getTituloEspectaculo())) {
							System.out.println(listaCriticas.get(i).getTituloEspectaculo());
							critica1.setCantidadValoraciones(listaCriticas.get(i).getCantidadValoraciones() + 1);
						}
					}

					CriticaDAO review = new CriticaDAO();
					review.crearCritica(critica1);
					response.sendRedirect("/Ejercicio2/VentanaPublicarCritica.html");

				} else {
					response.sendRedirect("/Ejercicio2/VentanaEspectaculoNoRealizado.html");
				}

			} catch (Exception e) {
				e.printStackTrace();

			}
		} else {
			response.setStatus(403);

		}

	}

}