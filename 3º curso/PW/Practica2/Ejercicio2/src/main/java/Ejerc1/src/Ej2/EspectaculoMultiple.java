package Ejerc1.src.Ej2;
import java.util.*;

public class EspectaculoMultiple extends EspectaculoDTO {
	private ArrayList <timeStamp> listaTime = new ArrayList<timeStamp>();

	public EspectaculoMultiple(String titulo, String descripcion, String categoria, Integer aforo) {
		super(titulo, descripcion, categoria, aforo);
		
	}

	public ArrayList<timeStamp> getListaTime() {
		return listaTime;
	}

	public void setListaTime(ArrayList<timeStamp> listaTime) {
		this.listaTime = listaTime;
	}		
}