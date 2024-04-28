/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_conic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:53:05 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/27 22:54:06 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf_bonus.h"

void project_cone(fdf **data, double angle)
{
    double scale_factor = tan(angle / 2.0);

    // Calculer les nouvelles coordonnées sur le plan de projection
    double new_x = (*data)->x / ((*data)->z * scale_factor);
    double new_y = (*data)->y / ((*data)->z * scale_factor);

    // Mettre à jour les coordonnées du (*data) projeté
    (*data)->x = new_x;
    (*data)->y = new_y;
    (*data)->z = 0; // Le plan de projection est en z = 0
}