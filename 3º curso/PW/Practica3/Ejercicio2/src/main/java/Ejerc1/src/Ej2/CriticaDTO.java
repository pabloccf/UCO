package Ejerc1.src.Ej2;

/**
 * Esta clase contiene el constructor, los get y los set de la critica.
 * @author Pablo López Gosálvez, Pablo Ibañez Fernández-Delgado y José Ángel Dorado González
 * @version openjdk version 11.0.12 2021-07-20
 */

public class CriticaDTO {
	private String titulo;
	private int puntuacion;
	private String texto;
	private int valoracion;
	private String owner;//Quiere hacer referencia al username
	private int cantidadValoraciones;
	private int id;
	private String TituloEspectaculo;

	/**
	 * Constructor de los datos de las críticas
	 * @param titulo Es el título de la crítica
	 * @param puntuacion Es la puntuación de la crítica
	 * @param texto Es una descripción sobre la crítica
	 * @param valoracion Es la valoración de la crítica
	 * @param owner Es el propietario de la crítica
	 * @param cantidadValoraciones Es la cantidad de veces que se ha valorado la crítica
	 */
	public CriticaDTO(String titulo, int puntuacion, String texto, int valoracion, String owner, int cantidadValoraciones, int id, String TituloEspectaculo) {
		this.titulo = titulo;
		this.puntuacion = puntuacion;
		this.texto = texto;
		this.valoracion = valoracion;
		this.owner = owner;
		this.cantidadValoraciones = cantidadValoraciones;
		this.id = id;
		this.TituloEspectaculo = TituloEspectaculo;
	}
	
	/**
	 * Constructor vacío de los datos de la crítica
	 */
	public CriticaDTO() {
		this.titulo = "";
		this.puntuacion = -1;
		this.texto = "";
		this.valoracion = 0;
		this.owner = "";
		this.cantidadValoraciones = 0;
		this.id = -1;
		this.TituloEspectaculo = "";
	}

	/**
	 * Método que devuelve el título de la crítica
	 * @return El título de la crítica
	 */
	public String getTitulo() {
		return titulo;
	}

	/**
	 * Método que establece un valor al título de la crítica
	 * @param titulo Es el título de la crítica que el usuario introduce por pantalla
	 */
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	/**
	 * Método que devuelve la puntuación de la crítica
	 * @return La puntuación de la crítica
	 */
	public int getPuntuacion() {
		return puntuacion;
	}

	/**
	 * Método que establece un valor a la puntuación de la crítica
	 * @param puntuacion Es la puntuación de la crítica que el usuario introduce por pantalla
	 */
	public void setPuntuacion(int puntuacion) {
		this.puntuacion = puntuacion;
	}

	/**
	 * Método que devuelve la descripción sobre la crítica
	 * @return La descripción sobre la crítica
	 */
	public String getTexto() {
		return texto;
	}

	/**
	 * Método que establece un valor a la descripción de la crítica
	 * @param texto Es la descripción de la crítica que el usuario introduce por pantalla
	 */
	public void setTexto(String texto) {
		this.texto = texto;
	}

	/**
	 * Método que devuelve la valoración sobre la crítica
	 * @return La valoración de la crítica
	 */
	public int getValoracion() {
		return valoracion;
	}

	/**
	 * Método que establece un valor a la valoración de la crítica
	 * @param valoracion Es la valoración de la crítica que el usuario introduce por pantalla
	 */
	public void setValoracion(int valoracion) {
		this.valoracion = valoracion;
	}

	/**
	 * Método que devuelve el propietario de la crítica
	 * @return El propietario de la crítica
	 */
	public String getOwner() {
		return owner;
	}

	/**
	 * Método que establece un valor al propietario de la crítica
	 * @param owner Es el propietario de la crítica que el usuario introduce por pantalla
	 */
	public void setOwner(String owner) {
		this.owner = owner;
	}

	/**
	 * Método que devuelve la cantidad de veces que se valora la crítica
	 * @return La cantidad de veces que valoran la crítica
	 */
	public int getCantidadValoraciones() {
		return cantidadValoraciones;
	}

	/**
	 * Método que establece un valor a la cantidad de veces que valoran la crítica
	 * @param cantidadValoraciones La cantidad de veces que valoran la crítica que el usuario introduce por pantalla
	 */
	public void setCantidadValoraciones(int cantidadValoraciones) {
		this.cantidadValoraciones = cantidadValoraciones;
	}
	
	/**
	 * Método que devuelve la cantidad de veces que se valora la crítica
	 * @return La cantidad de veces que valoran la crítica
	 */
	public int getID() {
		return id;
	}

	/**
	 * Método que establece un valor a la cantidad de veces que valoran la crítica
	 * @param cantidadValoraciones La cantidad de veces que valoran la crítica que el usuario introduce por pantalla
	 */
	public void setID(int id) {
		this.id = id;
	}
	
	/**
	 * Método que devuelve el titulo del espectaculo
	 * @return Titulo del espectaculo a realizar la critica
	 */
	public String getTituloEspectaculo() {
		return TituloEspectaculo;
	}

	/**
	 * Método que establece un valor al titulo del espectaculo
	 * @param TituloEspectaculo El titulo del espectaculo a realizar la critica
	 */
	public void setTituloEspectaculo(String TituloEspectaculo) {
		this.TituloEspectaculo = TituloEspectaculo;
	}
}