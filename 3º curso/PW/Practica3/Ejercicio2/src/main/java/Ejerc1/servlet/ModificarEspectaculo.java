package Ejerc1.servlet;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Ejerc1.src.Ej2.EspectaculoDTO;
import Ejerc1.src.DAOs.EspectaculoDAO;

/**
 * Servlet encargado de modificar un espectaculo
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/ModificarEspectaculo")
public class ModificarEspectaculo extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Es el constructor del servlet.
	 */
	public ModificarEspectaculo() {
		super();
		// TODO Auto-generated constructor stub
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.sendRedirect("/Ejercicio2/ModificarEspectaculo.html");
	}

	/**
	 * Esta función del servlet llama a las funciones de EspectaculoDAO que se
	 * encargan de modificar los parametros de un espectaculo
	 * 
	 * @param espectaculo1        es el objeto de tipo EspectaculoDAO que se encarga
	 *                            de dar acceso a las funciones del EspectaculoDAO
	 * @param espectaculoBorrado  es el objeto de tipo EspectaculoDTO el cual se
	 *                            desea borrar para añadir el modificado
	 * @param espectaculoAuxiliar es el objeto de tipo EspectaculoDTO el cual se va
	 *                            a cambiar por el borrado
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			/**
			 * Revisar el titulo que recibe.
			 **/
			String titulo2 = request.getParameter("tituloAntiguo");
			// String titulo = request.getParameter("tituloNuevo");
			String descripcion = request.getParameter("descripcion");
			String categoria = request.getParameter("categoria");
			String aforo_str = request.getParameter("aforo");
			int aforo = Integer.parseInt(aforo_str);
			String localidad = request.getParameter("localidad");
			String fecha = request.getParameter("fecha");
			String tipo = request.getParameter("tipo");
			String numeroEspectaculos_str = request.getParameter("numeroEspectaculos");
			int numeroEspectaculos = Integer.parseInt(numeroEspectaculos_str);
			String hora = request.getParameter("hora");
			String fechaFin = request.getParameter("fechaFin");
			String horaFin = request.getParameter("horaFin");
			String dia_str = request.getParameter("dia");
			int dia = Integer.parseInt(dia_str);
			int contador = 0;

			EspectaculoDAO espectaculo1 = new EspectaculoDAO();

			EspectaculoDTO espectaculoBorrado = new EspectaculoDTO();
			EspectaculoDTO espectaculoAuxiliar = new EspectaculoDTO();

			ArrayList<EspectaculoDTO> listaEspectaculo = new ArrayList<EspectaculoDTO>();
			listaEspectaculo = espectaculo1.ObtenerTodosEspectaculos();

			for (int i = 0; i < listaEspectaculo.size(); i++) {

				if (listaEspectaculo.get(i).getTitulo().equals(titulo2)) {

					espectaculoBorrado = espectaculo1.obtenerMostrarPorTitulo(titulo2);

					espectaculoAuxiliar.setTitulo(listaEspectaculo.get(i).getTitulo());
					espectaculoAuxiliar.setDescripcion(listaEspectaculo.get(i).getDescripcion());
					espectaculoAuxiliar.setCategoria(listaEspectaculo.get(i).getCategoria());
					espectaculoAuxiliar.setAforo(listaEspectaculo.get(i).getAforo());
					espectaculoAuxiliar.setEntradasVendidas(listaEspectaculo.get(i).getEntradasVendidas());
					espectaculoAuxiliar.setLocalidad(listaEspectaculo.get(i).getLocalidad());
					espectaculoAuxiliar.setFecha(listaEspectaculo.get(i).getFecha());
					espectaculoAuxiliar.setTipo(listaEspectaculo.get(i).getTipo());
					espectaculoAuxiliar.setEspectaculos(listaEspectaculo.get(i).getEspectaculos());
					espectaculoAuxiliar.setHora(listaEspectaculo.get(i).getHora());
					espectaculoAuxiliar.setFechaFin(listaEspectaculo.get(i).getFechaFin());
					espectaculoAuxiliar.setHoraFin(listaEspectaculo.get(i).getHoraFin());
					espectaculoAuxiliar.setDia(listaEspectaculo.get(i).getDia());
					contador++;

					espectaculo1.eliminarEspectaculo(espectaculoBorrado);
				} else {
					response.setStatus(404);
				}
			}

			/*
			 * if(titulo != null) {
			 * espectaculoAuxiliar.setTitulo(titulo);
			 * }
			 */

			if (!categoria.equals("")) {
				espectaculoAuxiliar.setCategoria(categoria);
			}

			if (!descripcion.equals("")) {
				espectaculoAuxiliar.setDescripcion(descripcion);
			}

			if (aforo != 0) {
				espectaculoAuxiliar.setAforo(aforo);
			}

			if (!localidad.equals("")) {
				espectaculoAuxiliar.setLocalidad(localidad);
			}

			if (!fecha.equals("")) {
				espectaculoAuxiliar.setFecha(fecha);
			}

			if (tipo.equals("Puntual") || tipo.equals("Temporada") || tipo.equals("Multiple")) {
				espectaculoAuxiliar.setTipo(tipo);
			}

			if (numeroEspectaculos != 0) {
				espectaculoAuxiliar.setEspectaculos(numeroEspectaculos);
			}

			if (!hora.equals("")) {
				espectaculoAuxiliar.setHora(hora);
			}

			if (!fechaFin.equals("")) {
				espectaculoAuxiliar.setFechaFin(fechaFin);
			}

			if (!horaFin.equals("")) {
				espectaculoAuxiliar.setHoraFin(horaFin);
			}

			if (dia >= 1 && dia <= 7) {
				espectaculoAuxiliar.setDia(dia);
			}

			if (tipo.equals("Puntual")) {
				espectaculoAuxiliar.setFechaFin("");
				espectaculoAuxiliar.setHoraFin("");
				espectaculoAuxiliar.setEspectaculos(1);
				espectaculoAuxiliar.setDia(0);
			}

			if (tipo.equals("Multiple")) {
				espectaculoAuxiliar.setFechaFin("");
				espectaculoAuxiliar.setHoraFin("");
				espectaculoAuxiliar.setDia(0);
			}

			if (contador > 0) {
				espectaculo1.crearEspectaculo(espectaculoAuxiliar);
				response.sendRedirect("/Ejercicio2/VentanaModificarEspectaculo.html");
			} else {
				RequestDispatcher dispatcher = request.getRequestDispatcher("VentanaEspectaculoNoModificado.html");
				dispatcher.include(request, response);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}