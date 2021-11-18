package Ejerc1.src.Ej2;

/**
 * Esta clase contiene el constructor, los get y los set de los espectaculos.
 * @author Pablo López Gosálvez, Pablo Ibañez Fernández-Delgado y José Ángel Dorado González
 * @version openjdk version 11.0.12 2021-07-20
 */

public class EspectaculoDTO {
	private String titulo;
	private String descripcion;
	private String categoria;
	private Integer aforo;
	private Integer entradasVendidas;
	private String localidad;
	private String fecha;
	
	/**
	 * Constructor de los datos de los espectáculos
	 * @param titulo Es el título del espectáculo
	 * @param descripcion Es la descripción del espectáculo
	 * @param categoria Es la categoría del espectáculo
	 * @param aforo Es el aforo del espectáculo
	 */
	public EspectaculoDTO(String titulo, String descripcion, String categoria, Integer aforo) {
		super();
		this.titulo = titulo;
		this.descripcion = descripcion;
		this.categoria = categoria;
		this.aforo = aforo;
		this.entradasVendidas = 0;
		this.localidad = "";
	}

	/**
	 * Constructor de los datos de los espectáculos
	 * @param titulo Es el título del espectáculo
	 * @param descripcion Es la descripción del espectáculo
	 * @param categoria Es la categoría del espectáculo
	 * @param aforo Es el aforo del espectáculo
	 * @param entradasVendidas Son las entradas vendidas de los espectáculos
	 * @param fecha Es la fecha del espectáculo
	 */
	public EspectaculoDTO(String titulo, String descripcion, String categoria, Integer aforo, Integer entradasVendidas, String fecha) {
		super();
		this.titulo = titulo;
		this.descripcion = descripcion;
		this.categoria = categoria;
		this.aforo = aforo;
		this.entradasVendidas = entradasVendidas;
		this.localidad = "";
		this.fecha = "";
	}

	/**
	 * Constructor vacío de los datos de los espectáculos
	 */
	public EspectaculoDTO() {
		this.titulo = "";
		this.descripcion = "";
		this.categoria = "";
		this.aforo = 0;
		this.entradasVendidas = 0;
		this.localidad = "";
		this.fecha = "";
	}

	/**
	 * Método que devuelve el título del espectáculo
	 * @return El título del espectáculo
	 */
	public String getTitulo() {
		return titulo;
	}

	/**
	 * Método que establece un valor al título del espectáculo
	 * @param titulo Es el título del espectáculo que el usuario introduce por pantalla
	 */
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	/**
	 * Método que devuelve la descripción sobre el espectáculo
	 * @return La descripción sobre el espectáculo
	 */
	public String getDescripcion() {
		return descripcion;
	}

	/**
	 * Método que establece un valor a la descripción del espectáculo
	 * @param texto Es la descripción del espectáculo que el usuario introduce por pantalla
	 */
	public void setDescripcion(String descripcion) {
		this.descripcion = descripcion;
	}

	/**
	 * Método que devuelve la categoría del espectáculo
	 * @return La categoría del espectáculo
	 */
	public String getCategoria() {
		return categoria;
	}

	/**
	 * Método que establece un valor a la categoría del espectáculo
	 * @param categoria Es la categoría del espectáculo que el usuario introduce por pantalla
	 */
	public void setCategoria(String categoria) {
		this.categoria = categoria;
	}

	/**
	 * Método que devuelve el aforo del espectáculo
	 * @return El aforo del espectáculo
	 */
	public Integer getAforo() {
		return aforo;
	}

	/**
	 * Método que establece un valor al aforo del espectáculo
	 * @param aforo Es el aforo del espectáculo que el usuario introduce por pantalla
	 */
	public void setAforo(Integer aforo) {
		this.aforo = aforo;
	}
		
	/**
	 * Método que devuelve el número de entradas vendidas del espectáculo
	 * @return El número de entradas vendidas del espectáculo
	 */
	public Integer getEntradasVendidas() {
		return entradasVendidas;
	}

	/**
	 * Método que establece un valor al número de entradas vendidas del espectáculo
	 * @param entradasVendidas Es el número de entradas vendidas del espectáculo que el usuario introduce por pantalla
	 */
	public void setEntradasVendidas(Integer entradasVendidas) {
		this.entradasVendidas = entradasVendidas;
	}
		
	/**
	 * Método que devuelve la localidad del espectáculo
	 * @return La localidad del espectáculo
	 */
	public String getLocalidad() {
		return localidad;
	}

	/**
	 * Método que establece un valor a la localidad del espectáculo
	 * @param localidad Es la localidad del espectáculo
	 */
	public void setLocalidad(String localidad) {
		this.localidad = localidad;
	}

	/**
	 * Método que devuelve la fecha del espectáculo
	 * @return La fecha del espectáculo
	 */
	public String getFecha() {
		return fecha;
	}

	/**
	 * Método que establece un valor a la fecha del espectáculo
	 * @param fecha Es la fecha del espectáculo que el usuario introduce por pantalla
	 */
	public void setFecha(String fecha) {
		this.fecha = fecha;
	}	
}