#include "file.h"

int readFile(int type) {
	//�����ļ�����
	if (type == 1) {
		bus *p;
		error = fopen_s(&sysFile, "Bus.txt", "r");
		if (error != 0) {
			return 0;
		}

		while (1) {
			p = (bus *)malloc(sizeof(bus));

			//��ȡ����
			if (EOF == fscanf_s(sysFile, "%s%d%d%d%d%s", p->plateNum, _countof(p->plateNum), &p->carRepairing, &p->capacity, &p->busNum, &p->route, p->modelNum, _countof(p->modelNum))) break;

			p->next = busList->next;
			busList->next = p;
		}
		if (sysFile) fclose(sysFile);
	}

	//˾���ļ�����
	else if (type == 2) {
		driver *p;
		error = fopen_s(&sysFile, "Driver.txt", "r");
		if (error != 0) {
			return 0;
		}

		while (1) {
			p = (driver *)malloc(sizeof(driver));

			//��ȡ����
			if (EOF == fscanf_s(sysFile, "%s%d%s%s", p->driverName, _countof(p->driverName), &p->age, p->phone, _countof(p->phone), p->currentPlate, _countof(p->currentPlate))) break;

			p->next = driverList->next;
			driverList->next = p;
		}
		if (sysFile) fclose(sysFile);
	}

	//·���ļ�����
	else if (type == 3) {
		route *p;
		error = fopen_s(&sysFile, "Route.txt", "r");
		if (error) return 0;

		while (1) {
			p = (route *)malloc(sizeof(route));

			//��ȡ����
			if (EOF == fscanf_s(sysFile, "%d%s%s%s%s%s", &p->routeName, p->station1, _countof(p->station1), p->station2, _countof(p->station2), p->station3, _countof(p->station3), p->station4, _countof(p->station4), p->station5, _countof(p->station5))) break;

			p->next = routeList->next;
			routeList->next = p;
		}
		if (sysFile) fclose(sysFile);
	}
	return 1;
}

int saveFile(int type) {

	//������Ϣ
	if (type == 1) {
	bus *p;
	error = fopen_s(&sysFile, "Bus.txt", "w");
	if (error != 0) return 0;

	p = busList->next;

	while (p) {
		fprintf(sysFile, "%s\t%d\t%d\t%d\t%d\t%s\n", p->plateNum, p->carRepairing, p->capacity, p->busNum, p->route, p->modelNum);
		p = p->next;
	}

	if (sysFile) fclose(sysFile);
}

	//˾����Ϣ
	else if (type == 2) {
		driver *p;
		error = fopen_s(&sysFile, "Driver.txt", "w");
		if (error != 0) return 0;

		p = driverList->next;

		while (p) {
			fprintf(sysFile, "%s\t%d\t%s\t%s\n", p->driverName, p->age, p->phone, p->currentPlate);
			p = p->next;
		}

		if (sysFile) fclose(sysFile);
	}

	//·����Ϣ
	else if (type == 3) {
		route *p;
		error = fopen_s(&sysFile, "Route.txt", "w");
		if (error) return 0;
		
		p = routeList->next;

		while (p) {
			fprintf(sysFile, "%d\t%s\t%s\t%s\t%s\t%s\n", p->routeName, p->station1, p->station2, p->station3, p->station4, p->station5);
			p = p->next;
		}

		if (sysFile) fclose(sysFile);
	}

	return 1;
}