﻿using Microsoft.AspNetCore.Identity;

namespace DataLayer.Entities
{
    public class AppUser : IdentityUser
    {
        public ICollection<Estimates> Estimates { get; set; }
    }
}