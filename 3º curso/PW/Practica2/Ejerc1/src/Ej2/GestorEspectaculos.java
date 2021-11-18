package Ej2;

import java.util.ArrayList;

import DAOs.EspectaculoDAO;

/**
 * Esta clase es la que se encarga de las funciones principales que puede tener un usuario dentro de nuestro programa
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */

public class GestorEspectaculos {
	private ArrayList<EspectaculoDTO> espectaculosList = new ArrayList<EspectaculoDTO>();
	//ArrayList <Espectaculo> listaEspectaculo = new ArrayList<Espectaculo>();
	
	private static GestorEspectaculos instance = null; 
    public static GestorEspectaculos getInstance() { 
        if (instance == null) {
            instance = new GestorEspectaculos();
        }

        return instance;
    }

  	private GestorEspectaculos() {

  	}

	/**
	 * Esta función se encarga de almacenar el espectáculo en una lista
	 * @param espectaculo Es un objeto de tipo EspectaculoDTO que almacenas en una lista
	 */
	public void AltaEspectaculo(EspectaculoDTO espectaculo) {
		//Almacenamos el espectaculo en una lista y de la lista lo vaciamos en el fichero 
		EspectaculoDAO espectaculoDao = new EspectaculoDAO();
		espectaculoDao.crearEspectaculo(espectaculo);
	}
  
	/**
	 * Esta función se encarga de eliminar de la lista un espectáculo
	 * @param espectaculo Es un objeto de tipo EspectaculoDTO que es el que quieres eliminar de la lista
	 */
	public void CancelarEspectaculo(EspectaculoDTO espectaculo) {
		//El usuario le pasa un espectaculo al que no puede asistir, lo elimininamos de la lista de los espectaculo y reescribimos el fichero
		EspectaculoDAO espectaculoDAO = new EspectaculoDAO();
		espectaculoDAO.eliminarEspectaculo(espectaculo);
	}
  
	/**
	 * Esta función se encarga de actualizar un espectáculo
	 * @param espectaculo Es un objeto de tipo EspectaculoDTO que es el que quieres sustituir de la lista
	 * @param titulo Es el título del espectáculo
	 */
	public void ActualizarEspectaculo(EspectaculoDTO espectaculo,String titulo) {
		EspectaculoDAO espectaculoDao = new EspectaculoDAO();
		espectaculosList = espectaculoDao.ObtenerTodosEspectaculos();
		for(int i=0; i<espectaculosList.size();i++) {
			if(espectaculosList.get(i).getTitulo().equals(titulo)) {
				espectaculoDao.eliminarEspectaculo(espectaculo);
				espectaculoDao.crearEspectaculo(espectaculo);
			}
		}
	}
  
	/**
	 * Esta función se encarga de la venta de entradas
	 * @param titulo Es el título del espectáculo del que quieres vender la entrada
	 */
	public void VentaEntradas(String titulo) {
		for(int i=0; i<espectaculosList.size();i++) {
			if(espectaculosList.get(i).getTitulo().equals(titulo)) {
				espectaculosList.get(i).setEntradasVendidas(espectaculosList.get(i).getEntradasVendidas()+1) ;
			}
		}
	}
  
	/**
	 * Esta función se encarga de decir las localidades disponibles que hay en un espectáculo
	 * @param fecha Es la fecha del espectáculo
	 * @return Devuelve la lista de los espectáculos con localidades disponible
	 */
	public ArrayList<EspectaculoDTO> LocalidadesDisponibles(String fecha) {
		//En esta hay problemas 
		ArrayList<EspectaculoDTO> result = new ArrayList<EspectaculoDTO>();
		for (int i = 0; i < espectaculosList.size(); i++) {
			EspectaculoDTO e = espectaculosList.get(i);

			if (e instanceof EspectaculoPuntual && ((EspectaculoPuntual)e).getFecha().equals(fecha)) {
				result.add(e);
			}

			else if (e instanceof EspectaculoMultiple) {
				EspectaculoMultiple em = (EspectaculoMultiple)e;
				for (int j = 0; j < em.getListaTime().size(); j++) {
					if (em.getListaTime().get(j).getFecha().equals(fecha)) {
						result.add(e);
					}
				}
			}

			else {
				EspectaculoTemporada et = (EspectaculoTemporada)e;
				String fechaInicio = et.getFechaInicio();
				String fechaFin = et.getFechaFin();

					//Asumimos que se usa el formato DD/MM/AAAA
					String[] fechaParts = fecha.split("/");
					String[] inicioParts = fechaInicio.split("/");
					String[] finParts = fechaFin.split("/");

					int fechaDia = Integer.parseInt(fechaParts[0]);
					int fechaMes = Integer.parseInt(fechaParts[1]);
					int fechaYear = Integer.parseInt(fechaParts[2]);

					int inicioDia = Integer.parseInt(inicioParts[0]);
					int inicioMes = Integer.parseInt(inicioParts[1]);
					int inicioYear = Integer.parseInt(inicioParts[2]);

					int finDia = Integer.parseInt(finParts[0]);
					int finMes = Integer.parseInt(finParts[1]);
					int finYear = Integer.parseInt(finParts[2]);

				if (fechaYear < finYear && fechaYear > inicioYear) {
					if (fechaMes < finMes && fechaMes > inicioMes) {
						if (fechaDia < finDia && fechaDia > inicioDia) {
							result.add(e);
						}
					}
				}
			}
		}

		return result;
	}
  
	/**
	 * Esta función se encarga de buscar espectáculos por el título
	 * @param titulo Es el título del espectáculo por el que vas a buscar
	 * @return Devuelve un objeto de tipo EspectaculoDTO que son los espectáculos encontrados por ese título
	 */
	public EspectaculoDTO BusquedaEspectaculosTitulo(String titulo) {
		EspectaculoDTO espectaculo = null;
		EspectaculoDAO espectaculoDao = new EspectaculoDAO();
		espectaculo = espectaculoDao.obtenerMostrarPorTitulo(titulo);
		return espectaculo;
	}
  
	/**
	 * Esta función se encarga de buscar espectáculos por la categoría
	 * @param categoria Es la categoría del espectáculo por el que vas a buscar
	 * @return Devuelve un objeto de tipo EspectaculoDTO que son los espectaculos encontrados por esa categoría
	 */
	public EspectaculoDTO BusquedaEspectaculosCategoria(String categoria) {
		EspectaculoDTO espectaculo = null;
		EspectaculoDAO espectaculoDao = new EspectaculoDAO();
		espectaculo = espectaculoDao.obtenerMostrarPorCategoria(categoria);
		return espectaculo;
	}
	
	/**
	 * Esta función se encarga de comprar las entradas de un espectáculo
	 * @param entradas Son las entradas disponibles del espectáculo
	 * @param titulo Es el título del espectáculo del que quieres comprar las entradas
	 * @return Devuelve true en el caso de que todo haya ido correctamente y false en caso contrario
	 */
	public boolean ComprarEntrada(Integer entradas, String titulo){
		EspectaculoDTO e = new EspectaculoDTO();
		e.setTitulo(titulo);
		
		EspectaculoDAO espectaculoDao = new EspectaculoDAO();
		espectaculosList = espectaculoDao.ObtenerTodosEspectaculos();
		
		for(int i = 0; i<espectaculosList.size();i++) {
			if(e.getTitulo().equals(espectaculosList.get(i).getTitulo())) {
				if((espectaculosList.get(i).getEntradasVendidas()+entradas)<=(espectaculosList.get(i).getAforo())) {
					espectaculosList.get(i).setEntradasVendidas(entradas);
					EspectaculoDAO espect = new EspectaculoDAO();
					espect.MeterEntradasVendidas(espectaculosList.get(i));
					return true;
				}	
			}
		}	
		return false;
	}
	
	/**
	 * Esta función se encarga de mostrar todos los espectáculos
	 */
	public void MostrarEspectaculos() {
		EspectaculoDAO espectaculoDao = new EspectaculoDAO();
		espectaculosList = espectaculoDao.ObtenerTodosEspectaculos();
		
		for(int i = 0; i<espectaculosList.size();i++) {
			System.out.println("Titulo: "+espectaculosList.get(i).getTitulo());
			System.out.println("Descripcion: "+espectaculosList.get(i).getDescripcion());
			System.out.println("Categoria: "+espectaculosList.get(i).getCategoria());
			System.out.println("Aforo: "+espectaculosList.get(i).getAforo());
			System.out.println("Entradas vendidas: "+espectaculosList.get(i).getEntradasVendidas());
			System.out.println("Localidad: "+espectaculosList.get(i).getLocalidad());
			System.out.println("Fecha: "+espectaculosList.get(i).getFecha());
			System.out.println("\n");
		}
	}

	/**
	 * Esta función se encarga de buscar espectáculos por la fecha
	 * @param fecha Es la fecha del que quieres buscar los espectáculos
	 * @return Devuelve la cantidad de espectáculos que hay en esa fecha introducida como parámetro
	 */
	public int BusquedaEspectaculosFecha(String fecha) {
		EspectaculoDTO espectaculo = new EspectaculoDTO();
		espectaculo.setFecha(fecha);
		EspectaculoDAO espectaculoDao = new EspectaculoDAO();
		espectaculosList = espectaculoDao.ObtenerTodosEspectaculos();
		int existe=0;
		
		for(int i = 0; i<espectaculosList.size();i++) {
			if(espectaculo.getFecha().equals(espectaculosList.get(i).getFecha())) {
				System.out.println("Titulo: "+espectaculosList.get(i).getTitulo());
				System.out.println("Descripcion: "+espectaculosList.get(i).getDescripcion());
				System.out.println("Categoria: "+espectaculosList.get(i).getCategoria());
				System.out.println("Aforo: "+espectaculosList.get(i).getAforo());
				System.out.println("Entradas vendidas: "+espectaculosList.get(i).getEntradasVendidas());
				System.out.println("Localidad: "+espectaculosList.get(i).getLocalidad());
				System.out.println("Fecha: "+espectaculosList.get(i).getFecha());
				System.out.println("\n");
				existe++;
			}
		}
		return existe;
	}
}